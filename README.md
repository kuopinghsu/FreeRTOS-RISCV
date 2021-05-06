# FreeRTOS for RISC-V
------------------------------------------------------------
This is an example to test <A Href="https://github.com/kuopinghsu/srv32">srv32</A> on FreeRTOS

# Build

    git clone --recursive https://github.com/kuopinghsu/FreeRTOS-RISCV
    cd FreeRTOS-RISCV && make

# Folder Lists

| Folder / File               | Description                                     |
| --------------------------- | ----------------------------------------------- |
| FreeRTOS-POSIX/             | FreeRTOS POSIX pthread source                   |
| Source/                     | FreeRTOS kernel source                          |
| Demo/examples/perf.c        | performance test                                |
| Demo/examples/pi_pthread.c  | PI pthread example                              |
| Demo/examples/pthread.c     | pthread example                                 |
| Demo/examples/queue.c       | queue example                                   |
| Demo/examples/sem.c         | semaphore example                               |
| Demo/examples/task.c        | task creation example                           |
| Demo/hartstone/             | Hartstone benchmark                             |


# Run

Requirement: Install the toolchains. See details in srv32 <A Href="https://github.com/kuopinghsu/srv32#building-toolchains">Building toolchains</A> section.

Clone <A Href="https://github.com/kuopinghsu/srv32">srv32</A> and copy the FreeRTOS's demo to srv32 'sw' folder. The demo can be run in the RTL and ISS simultor of srv32. See details in <A Href="https://github.com/kuopinghsu/srv32#freertos-support">FreeRTOS support</A> of srv32.

