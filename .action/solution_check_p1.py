#!/usr/bin/env python3
#
# Copyright 2021 Michael Shafae
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
""" Check student's submission; requires the main file and the
    template file from the original repository. """
# pexpect documentation
#  https://pexpect.readthedocs.io/en/stable/index.html
import logging
import pexpect
from srcutilities import solution_check_make


def run_p1(binary):
    """ Run part-1 """
    status = True
    values = (
        (34, 60, 10, 42, 'y', 77, 90, 42, 'n',),
        (34, 60, 77, 42, 'n',),
        (8, 23, 5, 63, 99, 42, 'y', 99, 23, 12, 51, 40, 42, 'n',),
        )
    for index, val in enumerate(values):
        logging.info('Test %d - %s', index + 1, val)
        status = status and  _run(binary, val)
        if not status:
            logging.error("Did not receive expected response. Halting test.")
            break
    return status


def _run(binary, values):
    """ This is the test for the BMR program given the inputs from run_p1 """
    status = False
    proc = pexpect.spawn(binary, timeout=1)
    #proc.logfile = sys.stdout.buffer
    values = list(map(str, values))

    for v in values:
        if v != 'y' and v != 'n':
            try:
                proc.expect(r'(?i)\s*What\'s\s+your\s+guess\?>\s*')
            except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
                logging.error('Could not find expected output.')
                logging.debug("%s", str(exception))
                logging.debug(str(proc))
                return status

            proc.sendline(v)
            if v != '42':
                try:
                    proc.expect(r'(?i)\s*(warmer|colder)\s*')
                except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
                    logging.error('Could not find expected output.')
                    logging.debug("%s", str(exception))
                    logging.debug(str(proc))
                    return status

        else:
            try:
                proc.expect(r'(?i)\s*Do\s+you\s+want\s+to\s+play\s+again\?\s+\(y\s+or\s+n\)>\s*')
            except (pexpect.exceptions.TIMEOUT, pexpect.exceptions.EOF) as exception:
                logging.error('Could not find expected output.')
                logging.debug("%s", str(exception))
                logging.debug(str(proc))
                return status

            proc.sendline(v)

    proc.expect(pexpect.EOF)
    proc.close()
    if proc.exitstatus == 0:
        status = True
    return status


if __name__ == '__main__':
    solution_check_make(run=run_p1)
