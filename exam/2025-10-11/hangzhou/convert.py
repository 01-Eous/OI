#!/bin/env python3
import sys
import tempfile
import shutil
import os
name = sys.argv[1]
with open(f"{name}.ans", "r") as answer, open(f"{name}.in", "r") as sys.stdin, tempfile.NamedTemporaryFile(mode='w+', delete=False) as file:
  temp_name = file.name
  n, m, q, typ = map(int, input().split())
  print(n, m, q, 1, file=file)
  print(input(), file=file)
  print(input(), file=file)
  lstans = 0
  for i in range(q):
    line = input().split()
    if not typ:
      for i in range(2, len(line)):
        line[i] = str(int(line[i]) ^ lstans)
    print(" ".join(line), file=file)
    if line[1] == 'q':
      lstans = int(answer.readline())
shutil.copy2(temp_name, f"{name}.in")
if os.path.exists(temp_name):
  os.unlink(temp_name)
print(f"Converted file {name} successfully.")