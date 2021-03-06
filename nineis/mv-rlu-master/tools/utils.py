#!/usr/bin/env python3

# SPDX-FileCopyrightText: Copyright (c) 2018-2019 Virginia Tech
# SPDX-License-Identifier: Apache-2.0

import os
import subprocess

def port_number():
    out = subprocess.check_output(["id -u %s" % os.environ['USER'], "-a"],
                                  stderr=subprocess.STDOUT,
                                  bufsize=1,
                                  universal_newlines=True,
                                  shell=True)
    return out.strip()
