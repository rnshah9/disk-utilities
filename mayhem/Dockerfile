FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo
RUN make -j8
WORKDIR /repo/m68k
RUN make -j8
RUN clang++ /repo/mayhem/fuzz_rnd16.cpp -fsanitize=fuzzer,address  -L /repo/libdisk/ -ldisk -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /repo/m68k/m68k_emulate /
COPY --from=builder /repo/libdisk/ /repo/libdisk
COPY --from=builder /fuzz /fuzz_rnd16
ENV LD_LIBRARY_PATH=/repo/libdisk
