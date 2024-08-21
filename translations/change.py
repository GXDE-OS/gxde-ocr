#!/usr/bin/env python3
import os
for i in os.listdir("."):
    os.rename(i, i.replace("durian", "gxde"))
