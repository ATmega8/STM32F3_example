CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c qp 

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Iinc -ICMSIS/Include -Ii2s
CFLAGS += -ICMSIS/Device/ST/STM32F37x/Include
CFLAGS += -D USE_STDPERIPH_DRIVER -DNDEBUG -finstrument-functions


SRCS = qa_ctor.c qa_usuba.c  qeq_init.c      qfsm_ini.c  qk.c        qmp_get.c         qte_ctr.c \
       qa_defer.c  qa_usub.c   qeq_lifo.c  qf_pool.c   qf_tick.c   qk_ext.c    qmp_init.c           qte_darm.c \
       qa_fifo.c   qep.c       qf_act.c    qf_psini.c  qhsm_dis.c  qk_mutex.c  qmp_put.c             qte_rarm.c \
       qa_get_.c   qf_gc.c     qf_pspub.c  qhsm_in.c      qmsm_dis.c        qvanilla.c \
       qa_lifo.c   qeq_fifo.c  qf_log2.c   qf_pwr2.c   qhsm_ini.c  qk_sched.c  qmsm_ini.c     qte_arm.c \
       qa_sub.c    qeq_get.c   qf_new.c    qfsm_dis.c  qhsm_top.c  qma_ctor.c         qte_ctor.c function.c


OBJS = $(SRCS:.c=.o)

.PHONY: libstm32f3_qp.a

all: libstm32f3_qp.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32f3_qp.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libstm32f3_qp.a
