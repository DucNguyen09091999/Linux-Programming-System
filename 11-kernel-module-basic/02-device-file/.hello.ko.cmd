cmd_/home/ducnguyen/Working_Space/Level1_course/Course/11-kernel-module-basic/02-device-file/hello.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/ducnguyen/Working_Space/Level1_course/Course/11-kernel-module-basic/02-device-file/hello.ko /home/ducnguyen/Working_Space/Level1_course/Course/11-kernel-module-basic/02-device-file/hello.o /home/ducnguyen/Working_Space/Level1_course/Course/11-kernel-module-basic/02-device-file/hello.mod.o ;  true