echo "Starting Abos build"
mkdir obj
make -C drivers/
make -C libc/
#make kernel/libk/Makefile
make -C kernel/
#make -C kernel/ clean 
