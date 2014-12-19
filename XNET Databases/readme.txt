The j1939kv.dbc file is the 'standard j1939 database'
We have then save-as to customize it for ECU communicaiton and LCD communication by changing the source address to match what the ECU and LCD expects. For the ECU, it expects a source address of 0x20. For the LCD, it generally expects a source address of 0x0 but the CCVS message needs a source address of 0x3.

The ECU J1939 DB.xml is added to NI-XNET as an alias named "ECU J1939 DB"
The LCD J1939 DB.xml is added to NI-XNET as an alias named "LCD J1939 DB"