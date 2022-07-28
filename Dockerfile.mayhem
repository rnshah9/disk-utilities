FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential

COPY . /repo
WORKDIR /repo
RUN make -j8
WORKDIR /repo/m68k
RUN make -j8

FROM ubuntu:20.04 as package
COPY --from=builder /repo/m68k/m68k_emulate /
