all: freestanding normal

freestanding:
	$(CC) freestanding.c -o freestanding -Os -nostdlib -ffreestanding -m64
	strip freestanding

normal:
	$(CC) normal.c -o normal -Os -m64
	strip normal

clean:
	rm freestanding normal

compare: freestanding normal
	@echo ""
	@echo "==== COMPARING SIZES ===="
	@echo "freestanding program: `wc -c < freestanding`"
	@echo "normal program:       `wc -c < normal`"

.PHONY: freestanding normal
