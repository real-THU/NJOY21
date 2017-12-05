FROM debian:latest

RUN apt update && apt upgrade -y && \
    apt install g++ gfortran cmake python3 git -y && \
    git clone https://github.com/njoy/NJOY21.git &&\
    cd NJOY21 && \
    python3 ./metaconfigure/fetch_subprojects.py && \
    mkdir build && cd build &&\
    cmake -Dfetched_subprojects=TRUE .. && \
    make

ENTRYPOINT [ "/bin/bash" ]
