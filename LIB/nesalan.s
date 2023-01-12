;written by Alan Files
;version 1.0, 1/11/2023

.export _serial_data

.segment "CODE"

;void serial_data(unsigned char data);
_serial_data:
	tay
	ldx #0
	rts
	
	