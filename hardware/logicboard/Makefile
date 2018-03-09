TARGET=geyser-001

$(TARGET).zip: files.txt $(TARGET).cmp $(TARGET).gpi $(TARGET).plc $(TARGET).sol $(TARGET).stc $(TARGET).sts $(TARGET).out $(TARGET).dri $(TARGET).drd
	zip $@ $+

all: $(TARGET).zip
