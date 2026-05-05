import mmap
import struct
import sys
import time

FORMAT = "<32s i 2i f"   
SIZE = struct.calcsize(FORMAT)

with open(f"/dev/shm/Person_info", "rb") as f:
    with mmap.mmap(f.fileno(), SIZE, prot=mmap.PROT_READ) as mm:
        while True:
            name_b, age, h0, h1, weight = struct.unpack(FORMAT, mm[:SIZE])
            print(name_b.rstrip(b'\x00').decode(), age, (h0, h1), weight)
            time.sleep(0.5)
