wsl sh ./clean.sh
wsl sh ./headers.sh
wsl sh ./build.sh
wsl sudo sh ./iso.sh
qemu-system-x86_64 -cdrom ./Samarium_OS.iso -serial file:serial.txt