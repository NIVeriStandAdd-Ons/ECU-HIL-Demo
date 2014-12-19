<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
	<Item Name="RT PXI Target" Type="RT PXI Chassis">
		<Property Name="alias.name" Type="Str">RT PXI Target</Property>
		<Property Name="alias.value" Type="Str">10.15.1.68</Property>
		<Property Name="CCSymbols" Type="Str">TARGET_TYPE,RT;OS,PharLap;CPU,x86;</Property>
		<Property Name="host.ResponsivenessCheckEnabled" Type="Bool">true</Property>
		<Property Name="host.ResponsivenessCheckPingDelay" Type="UInt">5000</Property>
		<Property Name="host.ResponsivenessCheckPingTimeout" Type="UInt">1000</Property>
		<Property Name="host.TargetCPUID" Type="UInt">3</Property>
		<Property Name="host.TargetOSID" Type="UInt">15</Property>
		<Property Name="target.cleanupVisa" Type="Bool">false</Property>
		<Property Name="target.FPProtocolGlobals_ControlTimeLimit" Type="Int">300</Property>
		<Property Name="target.getDefault-&gt;WebServer.Port" Type="Int">80</Property>
		<Property Name="target.getDefault-&gt;WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.IOScan.Faults" Type="Str"></Property>
		<Property Name="target.IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="target.IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="target.IOScan.Period" Type="UInt">10000</Property>
		<Property Name="target.IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="target.IOScan.Priority" Type="UInt">0</Property>
		<Property Name="target.IOScan.ReportModeConflict" Type="Bool">true</Property>
		<Property Name="target.IsRemotePanelSupported" Type="Bool">true</Property>
		<Property Name="target.RTCPULoadMonitoringEnabled" Type="Bool">true</Property>
		<Property Name="target.RTDebugWebServerHTTPPort" Type="Int">8001</Property>
		<Property Name="target.RTTarget.ApplicationPath" Type="Path">/c/ni-rt/startup/startup.rtexe</Property>
		<Property Name="target.RTTarget.EnableFileSharing" Type="Bool">true</Property>
		<Property Name="target.RTTarget.IPAccess" Type="Str">+*</Property>
		<Property Name="target.RTTarget.LaunchAppAtBoot" Type="Bool">false</Property>
		<Property Name="target.RTTarget.VIPath" Type="Path">/c/ni-rt/startup</Property>
		<Property Name="target.server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.tcp.access" Type="Str">+*</Property>
		<Property Name="target.server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="target.server.tcp.paranoid" Type="Bool">true</Property>
		<Property Name="target.server.tcp.port" Type="Int">3363</Property>
		<Property Name="target.server.tcp.serviceName" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.tcp.serviceName.default" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.vi.access" Type="Str">+*</Property>
		<Property Name="target.server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="target.server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.WebServer.Config" Type="Str">Listen 8000

NI.ServerName default
DocumentRoot "$LVSERVER_DOCROOT"
TypesConfig "$LVSERVER_CONFIGROOT/mime.types"
DirectoryIndex index.htm
WorkerLimit 10
InactivityTimeout 60

LoadModulePath "$LVSERVER_MODULEPATHS"
LoadModule LVAuth lvauthmodule
LoadModule LVRFP lvrfpmodule

#
# Pipeline Definition
#

SetConnector netConnector

AddHandler LVAuth
AddHandler LVRFP

AddHandler fileHandler ""

AddOutputFilter chunkFilter


</Property>
		<Property Name="target.WebServer.Enabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogEnabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogPath" Type="Path">/c/ni-rt/system/www/www.log</Property>
		<Property Name="target.WebServer.Port" Type="Int">80</Property>
		<Property Name="target.WebServer.RootPath" Type="Path">/c/ni-rt/system/www</Property>
		<Property Name="target.WebServer.TcpAccess" Type="Str">c+*</Property>
		<Property Name="target.WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.WebServer.ViAccess" Type="Str">+*</Property>
		<Property Name="target.webservices.SecurityAPIKey" Type="Str">PqVr/ifkAQh+lVrdPIykXlFvg12GhhQFR8H9cUhphgg=:pTe9HRlQuMfJxAG6QCGq7UvoUpJzAzWGKy5SbZ+roSU=</Property>
		<Property Name="target.webservices.ValidTimestampWindow" Type="Int">15</Property>
		<Item Name="Chassis" Type="MXI RIO Chassis">
			<Property Name="crio.ProgrammingMode" Type="Str">fpga</Property>
			<Property Name="crio.ResourceID" Type="Str">RIO0</Property>
			<Property Name="crio.Type" Type="Str">NI 9155</Property>
			<Item Name="FPGA Target 2" Type="FPGA Target">
				<Property Name="AutoRun" Type="Bool">false</Property>
				<Property Name="configString.guid" Type="Str">{02202DE3-A694-4DD7-AECF-5B60CA45CD59}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=bool{07C239CC-BAE4-4856-BFF7-64C4324E5AB6}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8{0AF9FB6C-B4A6-423C-819A-CD349389EA28}resource=/crio_Knock/AO11;0;WriteMethodType=i16{0FC6B6FC-7829-46D9-ADDD-4DF586F0F7E8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=bool{1437F7DC-E6F7-4AB2-B58E-8D03EAD3CA7E}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8{1C6766E5-1A3C-430D-8326-FB647C9F2FB2}resource=/crio_Knock/AO6;0;WriteMethodType=i16{1DBF33B1-2A26-4EB0-94AD-870680DDE992}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{25EDB220-032D-453D-A786-5AB17F1BF0DB}resource=/crio_Knock/AO2;0;WriteMethodType=i16{26FD48E0-4F9D-4E7C-8B57-CB9F01686579}resource=/crio_Knock/AO8;0;WriteMethodType=i16{2B9E4128-0656-42D9-9B5D-577C10F0DD00}resource=/crio_Knock/AO14;0;WriteMethodType=i16{2BCE6392-8B67-4549-80BB-434FCD7B0A0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=bool{31E7088A-C2A3-40C6-BE3F-C36AACCE97C8}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{32179FED-233C-470D-A71A-D006E4C716BD}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool{395360AE-FC7E-4A4F-8192-94FA439D9497}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E{3EFF009C-9DF1-45FE-9E0F-382F14C61FC5}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=bool{4021BA7F-0DE2-4F42-960B-14A43FB02452}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{44F9204E-A80A-456D-8DC3-3611DE27644C}resource=/crio_Knock/AO7;0;WriteMethodType=i16{4F904FB8-88A3-4986-8B83-745601732776}resource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8{66A5FAC6-E477-4D54-A5CA-F1C0BFF1AA0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=bool{67DD4EFE-7DE6-480B-8859-83F0B9020C9A}resource=/crio_Knock/AO1;0;WriteMethodType=i16{6A199E15-06DC-4E53-A876-53D42860FEBB}resource=/crio_Knock/AO4;0;WriteMethodType=i16{6AFA68F2-1CEA-45E4-AF9D-1DBDDEE9221F}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool{6CA1580B-158E-447F-B91B-4A477DD8E5B8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=bool{770B7E7C-EBD2-4696-BDDB-9032CBA3532C}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool{7E4F35BA-8894-43D5-8CDB-7530479B9C71}resource=/crio_Knock/AO9;0;WriteMethodType=i16{81622B9F-7DD7-47C5-9BF1-DF6A8409716B}resource=/crio_Knock/AO15;0;WriteMethodType=i16{817C474E-AE49-4F88-AE61-EDD84EB653B7}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=bool{8498A9D3-D883-4A4A-A168-DF2121DB20CC}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=bool{87309049-5397-4004-81C6-EBABAB226716}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=bool{882762C2-7F73-4D69-83F6-A25D0460BDA3}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool{90C9D34C-7E8B-4943-A8B7-C277B569BC25}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=bool{944F353F-29B1-400D-8753-C12575C07951}resource=/Chassis Temperature;0;ReadMethodType=i16{9565469F-3D92-4663-9A6E-7702976B0FE0}resource=/crio_Knock/AO3;0;WriteMethodType=i16{966C612D-1E03-45B8-8970-F0EFF0AB6A18}resource=/crio_Knock/AO13;0;WriteMethodType=i16{A5578FC0-59CF-4746-808D-498A3AFCAD98}resource=/crio_Knock/AO12;0;WriteMethodType=i16{A80D0CA0-8C79-4E9A-AF35-0F3E0DEC30ED}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool{AEA6723E-93A2-430B-8017-B8D84E64165E}resource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8{BC12DA06-802A-4DAF-9292-FA208C19779F}[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]{BD6DAD3B-C8C5-4554-8F5A-860028091801}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=bool{C0AF8353-A1BB-496D-91BF-06C927E70CFF}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool{C3CE3325-45B0-4AA1-AE19-912C2138C34D}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool{C4643414-0D6C-4584-9A87-035240459863}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8{C9A4F536-0F4D-4A22-89E4-6E70499FDE38}resource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8{D3302C5B-F15B-4EC5-BA01-2DE162097459}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=bool{DB749568-98D0-4F46-AF6E-261A9499D830}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool{E1CAFA73-ED58-4051-95EF-F88DFFDD1083}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=bool{E7FA63C6-7B7A-4083-AB48-3A5621E04F84}resource=/crio_Knock/AO5;0;WriteMethodType=i16{EA12F708-40D2-4AD0-A134-D8875FBF65BE}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=bool{EBD4BDE2-6DCA-4EE2-B680-CBB6905B611F}resource=/crio_Knock/AO10;0;WriteMethodType=i16{ED7DF807-828C-4F1A-B0E8-16E9CEF5C56A}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{F6BB1360-1C3A-4364-961E-DFC7C1BCDAAE}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool{FA206391-3454-43A9-BDE2-2B90DFF7AE99}resource=/crio_Knock/AO0;0;WriteMethodType=i16NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
				<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E9474/DO0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool9474/DO1ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool9474/DO2ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool9474/DO3ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool9474/DO4ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool9474/DO5ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool9474/DO6ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool9474/DO7:0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u89474/DO7ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool9474[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16Fuel/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=boolFuel/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=boolFuel/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=boolFuel/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=boolFuel/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=boolFuel/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8Fuel/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=boolFuel[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Knock/AO0resource=/crio_Knock/AO0;0;WriteMethodType=i16Knock/AO10resource=/crio_Knock/AO10;0;WriteMethodType=i16Knock/AO11resource=/crio_Knock/AO11;0;WriteMethodType=i16Knock/AO12resource=/crio_Knock/AO12;0;WriteMethodType=i16Knock/AO13resource=/crio_Knock/AO13;0;WriteMethodType=i16Knock/AO14resource=/crio_Knock/AO14;0;WriteMethodType=i16Knock/AO15resource=/crio_Knock/AO15;0;WriteMethodType=i16Knock/AO1resource=/crio_Knock/AO1;0;WriteMethodType=i16Knock/AO2resource=/crio_Knock/AO2;0;WriteMethodType=i16Knock/AO3resource=/crio_Knock/AO3;0;WriteMethodType=i16Knock/AO4resource=/crio_Knock/AO4;0;WriteMethodType=i16Knock/AO5resource=/crio_Knock/AO5;0;WriteMethodType=i16Knock/AO6resource=/crio_Knock/AO6;0;WriteMethodType=i16Knock/AO7resource=/crio_Knock/AO7;0;WriteMethodType=i16Knock/AO8resource=/crio_Knock/AO8;0;WriteMethodType=i16Knock/AO9resource=/crio_Knock/AO9;0;WriteMethodType=i16Knock[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Sleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSpark/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=boolSpark/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=boolSpark/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=boolSpark/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=boolSpark/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=boolSpark/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8Spark/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=boolSpark[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]USER FPGA1 LEDresource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA1 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=boolUSER FPGA2 LEDresource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA2 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=boolUSER FPGA3 LEDresource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA3 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool</Property>
				<Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA</Property>
				<Property Name="NI.LV.FPGA.Version" Type="Int">6</Property>
				<Property Name="Resource Name" Type="Str">RIO0</Property>
				<Property Name="Target Class" Type="Str">NI 9155</Property>
				<Property Name="Top-Level Timing Source" Type="Str">40 MHz Onboard Clock</Property>
				<Property Name="Top-Level Timing Source Is Default" Type="Bool">true</Property>
				<Item Name="9474" Type="Folder">
					<Item Name="9474/DO0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{882762C2-7F73-4D69-83F6-A25D0460BDA3}</Property>
					</Item>
					<Item Name="9474/DO1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F6BB1360-1C3A-4364-961E-DFC7C1BCDAAE}</Property>
					</Item>
					<Item Name="9474/DO2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{A80D0CA0-8C79-4E9A-AF35-0F3E0DEC30ED}</Property>
					</Item>
					<Item Name="9474/DO3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{770B7E7C-EBD2-4696-BDDB-9032CBA3532C}</Property>
					</Item>
					<Item Name="9474/DO4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6AFA68F2-1CEA-45E4-AF9D-1DBDDEE9221F}</Property>
					</Item>
					<Item Name="9474/DO5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{32179FED-233C-470D-A71A-D006E4C716BD}</Property>
					</Item>
					<Item Name="9474/DO6" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO6</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C3CE3325-45B0-4AA1-AE19-912C2138C34D}</Property>
					</Item>
					<Item Name="9474/DO7" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO7</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C0AF8353-A1BB-496D-91BF-06C927E70CFF}</Property>
					</Item>
					<Item Name="9474/DO7:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_9474/DO7:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C4643414-0D6C-4584-9A87-035240459863}</Property>
					</Item>
				</Item>
				<Item Name="Chassis I/O" Type="Folder">
					<Item Name="Chassis Temperature" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Chassis Temperature</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{944F353F-29B1-400D-8753-C12575C07951}</Property>
					</Item>
					<Item Name="Sleep" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Sleep</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{4021BA7F-0DE2-4F42-960B-14A43FB02452}</Property>
					</Item>
					<Item Name="USER FPGA1 LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/USER FPGA1 LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{4F904FB8-88A3-4986-8B83-745601732776}</Property>
					</Item>
					<Item Name="USER FPGA1 Switch" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/USER FPGA1 Switch</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{87309049-5397-4004-81C6-EBABAB226716}</Property>
					</Item>
					<Item Name="USER FPGA2 LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/USER FPGA2 LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C9A4F536-0F4D-4A22-89E4-6E70499FDE38}</Property>
					</Item>
					<Item Name="USER FPGA2 Switch" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/USER FPGA2 Switch</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{02202DE3-A694-4DD7-AECF-5B60CA45CD59}</Property>
					</Item>
					<Item Name="USER FPGA3 LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/USER FPGA3 LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{AEA6723E-93A2-430B-8017-B8D84E64165E}</Property>
					</Item>
					<Item Name="USER FPGA3 Switch" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/USER FPGA3 Switch</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{DB749568-98D0-4F46-AF6E-261A9499D830}</Property>
					</Item>
				</Item>
				<Item Name="Fuel" Type="Folder">
					<Item Name="Fuel/DI0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D3302C5B-F15B-4EC5-BA01-2DE162097459}</Property>
					</Item>
					<Item Name="Fuel/DI1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6CA1580B-158E-447F-B91B-4A477DD8E5B8}</Property>
					</Item>
					<Item Name="Fuel/DI2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{0FC6B6FC-7829-46D9-ADDD-4DF586F0F7E8}</Property>
					</Item>
					<Item Name="Fuel/DI3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{2BCE6392-8B67-4549-80BB-434FCD7B0A0A}</Property>
					</Item>
					<Item Name="Fuel/DI4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{BD6DAD3B-C8C5-4554-8F5A-860028091801}</Property>
					</Item>
					<Item Name="Fuel/DI5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{8498A9D3-D883-4A4A-A168-DF2121DB20CC}</Property>
					</Item>
					<Item Name="Fuel/DI5:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Fuel/DI5:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{07C239CC-BAE4-4856-BFF7-64C4324E5AB6}</Property>
					</Item>
				</Item>
				<Item Name="Knock" Type="Folder">
					<Item Name="Knock/AO0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FA206391-3454-43A9-BDE2-2B90DFF7AE99}</Property>
					</Item>
					<Item Name="Knock/AO1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{67DD4EFE-7DE6-480B-8859-83F0B9020C9A}</Property>
					</Item>
					<Item Name="Knock/AO2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{25EDB220-032D-453D-A786-5AB17F1BF0DB}</Property>
					</Item>
					<Item Name="Knock/AO3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9565469F-3D92-4663-9A6E-7702976B0FE0}</Property>
					</Item>
					<Item Name="Knock/AO4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6A199E15-06DC-4E53-A876-53D42860FEBB}</Property>
					</Item>
					<Item Name="Knock/AO5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E7FA63C6-7B7A-4083-AB48-3A5621E04F84}</Property>
					</Item>
					<Item Name="Knock/AO6" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO6</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{1C6766E5-1A3C-430D-8326-FB647C9F2FB2}</Property>
					</Item>
					<Item Name="Knock/AO7" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO7</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{44F9204E-A80A-456D-8DC3-3611DE27644C}</Property>
					</Item>
					<Item Name="Knock/AO8" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO8</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{26FD48E0-4F9D-4E7C-8B57-CB9F01686579}</Property>
					</Item>
					<Item Name="Knock/AO9" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO9</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{7E4F35BA-8894-43D5-8CDB-7530479B9C71}</Property>
					</Item>
					<Item Name="Knock/AO10" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO10</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{EBD4BDE2-6DCA-4EE2-B680-CBB6905B611F}</Property>
					</Item>
					<Item Name="Knock/AO11" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO11</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{0AF9FB6C-B4A6-423C-819A-CD349389EA28}</Property>
					</Item>
					<Item Name="Knock/AO12" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO12</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{A5578FC0-59CF-4746-808D-498A3AFCAD98}</Property>
					</Item>
					<Item Name="Knock/AO13" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO13</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{966C612D-1E03-45B8-8970-F0EFF0AB6A18}</Property>
					</Item>
					<Item Name="Knock/AO14" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO14</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{2B9E4128-0656-42D9-9B5D-577C10F0DD00}</Property>
					</Item>
					<Item Name="Knock/AO15" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Knock/AO15</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{81622B9F-7DD7-47C5-9BF1-DF6A8409716B}</Property>
					</Item>
				</Item>
				<Item Name="Spark" Type="Folder">
					<Item Name="Spark/DI0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{90C9D34C-7E8B-4943-A8B7-C277B569BC25}</Property>
					</Item>
					<Item Name="Spark/DI1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{817C474E-AE49-4F88-AE61-EDD84EB653B7}</Property>
					</Item>
					<Item Name="Spark/DI2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{EA12F708-40D2-4AD0-A134-D8875FBF65BE}</Property>
					</Item>
					<Item Name="Spark/DI3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E1CAFA73-ED58-4051-95EF-F88DFFDD1083}</Property>
					</Item>
					<Item Name="Spark/DI4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{66A5FAC6-E477-4D54-A5CA-F1C0BFF1AA0A}</Property>
					</Item>
					<Item Name="Spark/DI5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{3EFF009C-9DF1-45FE-9E0F-382F14C61FC5}</Property>
					</Item>
					<Item Name="Spark/DI5:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>Auto</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Spark/DI5:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{1437F7DC-E6F7-4AB2-B58E-8D03EAD3CA7E}</Property>
					</Item>
				</Item>
				<Item Name="40 MHz Onboard Clock" Type="FPGA Base Clock">
					<Property Name="FPGA.PersistentID" Type="Str">{395360AE-FC7E-4A4F-8192-94FA439D9497}</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig" Type="Str">ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.Accuracy" Type="Dbl">100</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ClockSignalName" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.NominalFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.PeakPeriodJitter" Type="Dbl">250</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ResourceName" Type="Str">40 MHz Onboard Clock</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.SupportAndRequireRuntimeEnableDisable" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.TopSignalConnect" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.VariableFrequency" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.Valid" Type="Bool">true</Property>
					<Property Name="NI.LV.FPGA.Version" Type="Int">5</Property>
				</Item>
				<Item Name="9474" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 1</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9474</Property>
					<Property Name="cRIOModule.DIO3_0InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.DIO7_4InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.NumSyncRegs" Type="Str">11111111</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{1DBF33B1-2A26-4EB0-94AD-870680DDE992}</Property>
				</Item>
				<Item Name="Digital Filter.vi" Type="VI" URL="../Digital Filter.vi">
					<Property Name="configString.guid" Type="Str">{02202DE3-A694-4DD7-AECF-5B60CA45CD59}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=bool{07C239CC-BAE4-4856-BFF7-64C4324E5AB6}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8{0AF9FB6C-B4A6-423C-819A-CD349389EA28}resource=/crio_Knock/AO11;0;WriteMethodType=i16{0FC6B6FC-7829-46D9-ADDD-4DF586F0F7E8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=bool{1437F7DC-E6F7-4AB2-B58E-8D03EAD3CA7E}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8{1C6766E5-1A3C-430D-8326-FB647C9F2FB2}resource=/crio_Knock/AO6;0;WriteMethodType=i16{1DBF33B1-2A26-4EB0-94AD-870680DDE992}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{25EDB220-032D-453D-A786-5AB17F1BF0DB}resource=/crio_Knock/AO2;0;WriteMethodType=i16{26FD48E0-4F9D-4E7C-8B57-CB9F01686579}resource=/crio_Knock/AO8;0;WriteMethodType=i16{2B9E4128-0656-42D9-9B5D-577C10F0DD00}resource=/crio_Knock/AO14;0;WriteMethodType=i16{2BCE6392-8B67-4549-80BB-434FCD7B0A0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=bool{31E7088A-C2A3-40C6-BE3F-C36AACCE97C8}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{32179FED-233C-470D-A71A-D006E4C716BD}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool{395360AE-FC7E-4A4F-8192-94FA439D9497}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E{3EFF009C-9DF1-45FE-9E0F-382F14C61FC5}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=bool{4021BA7F-0DE2-4F42-960B-14A43FB02452}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{44F9204E-A80A-456D-8DC3-3611DE27644C}resource=/crio_Knock/AO7;0;WriteMethodType=i16{4F904FB8-88A3-4986-8B83-745601732776}resource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8{66A5FAC6-E477-4D54-A5CA-F1C0BFF1AA0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=bool{67DD4EFE-7DE6-480B-8859-83F0B9020C9A}resource=/crio_Knock/AO1;0;WriteMethodType=i16{6A199E15-06DC-4E53-A876-53D42860FEBB}resource=/crio_Knock/AO4;0;WriteMethodType=i16{6AFA68F2-1CEA-45E4-AF9D-1DBDDEE9221F}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool{6CA1580B-158E-447F-B91B-4A477DD8E5B8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=bool{770B7E7C-EBD2-4696-BDDB-9032CBA3532C}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool{7E4F35BA-8894-43D5-8CDB-7530479B9C71}resource=/crio_Knock/AO9;0;WriteMethodType=i16{81622B9F-7DD7-47C5-9BF1-DF6A8409716B}resource=/crio_Knock/AO15;0;WriteMethodType=i16{817C474E-AE49-4F88-AE61-EDD84EB653B7}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=bool{8498A9D3-D883-4A4A-A168-DF2121DB20CC}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=bool{87309049-5397-4004-81C6-EBABAB226716}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=bool{882762C2-7F73-4D69-83F6-A25D0460BDA3}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool{90C9D34C-7E8B-4943-A8B7-C277B569BC25}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=bool{944F353F-29B1-400D-8753-C12575C07951}resource=/Chassis Temperature;0;ReadMethodType=i16{9565469F-3D92-4663-9A6E-7702976B0FE0}resource=/crio_Knock/AO3;0;WriteMethodType=i16{966C612D-1E03-45B8-8970-F0EFF0AB6A18}resource=/crio_Knock/AO13;0;WriteMethodType=i16{A5578FC0-59CF-4746-808D-498A3AFCAD98}resource=/crio_Knock/AO12;0;WriteMethodType=i16{A80D0CA0-8C79-4E9A-AF35-0F3E0DEC30ED}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool{AEA6723E-93A2-430B-8017-B8D84E64165E}resource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8{BC12DA06-802A-4DAF-9292-FA208C19779F}[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]{BD6DAD3B-C8C5-4554-8F5A-860028091801}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=bool{C0AF8353-A1BB-496D-91BF-06C927E70CFF}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool{C3CE3325-45B0-4AA1-AE19-912C2138C34D}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool{C4643414-0D6C-4584-9A87-035240459863}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8{C9A4F536-0F4D-4A22-89E4-6E70499FDE38}resource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8{D3302C5B-F15B-4EC5-BA01-2DE162097459}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=bool{DB749568-98D0-4F46-AF6E-261A9499D830}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool{E1CAFA73-ED58-4051-95EF-F88DFFDD1083}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=bool{E7FA63C6-7B7A-4083-AB48-3A5621E04F84}resource=/crio_Knock/AO5;0;WriteMethodType=i16{EA12F708-40D2-4AD0-A134-D8875FBF65BE}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=bool{EBD4BDE2-6DCA-4EE2-B680-CBB6905B611F}resource=/crio_Knock/AO10;0;WriteMethodType=i16{ED7DF807-828C-4F1A-B0E8-16E9CEF5C56A}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{F6BB1360-1C3A-4364-961E-DFC7C1BCDAAE}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool{FA206391-3454-43A9-BDE2-2B90DFF7AE99}resource=/crio_Knock/AO0;0;WriteMethodType=i16NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E9474/DO0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool9474/DO1ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool9474/DO2ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool9474/DO3ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool9474/DO4ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool9474/DO5ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool9474/DO6ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool9474/DO7:0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u89474/DO7ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool9474[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16Fuel/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=boolFuel/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=boolFuel/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=boolFuel/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=boolFuel/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=boolFuel/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8Fuel/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=boolFuel[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Knock/AO0resource=/crio_Knock/AO0;0;WriteMethodType=i16Knock/AO10resource=/crio_Knock/AO10;0;WriteMethodType=i16Knock/AO11resource=/crio_Knock/AO11;0;WriteMethodType=i16Knock/AO12resource=/crio_Knock/AO12;0;WriteMethodType=i16Knock/AO13resource=/crio_Knock/AO13;0;WriteMethodType=i16Knock/AO14resource=/crio_Knock/AO14;0;WriteMethodType=i16Knock/AO15resource=/crio_Knock/AO15;0;WriteMethodType=i16Knock/AO1resource=/crio_Knock/AO1;0;WriteMethodType=i16Knock/AO2resource=/crio_Knock/AO2;0;WriteMethodType=i16Knock/AO3resource=/crio_Knock/AO3;0;WriteMethodType=i16Knock/AO4resource=/crio_Knock/AO4;0;WriteMethodType=i16Knock/AO5resource=/crio_Knock/AO5;0;WriteMethodType=i16Knock/AO6resource=/crio_Knock/AO6;0;WriteMethodType=i16Knock/AO7resource=/crio_Knock/AO7;0;WriteMethodType=i16Knock/AO8resource=/crio_Knock/AO8;0;WriteMethodType=i16Knock/AO9resource=/crio_Knock/AO9;0;WriteMethodType=i16Knock[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Sleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSpark/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=boolSpark/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=boolSpark/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=boolSpark/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=boolSpark/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=boolSpark/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8Spark/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=boolSpark[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]USER FPGA1 LEDresource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA1 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=boolUSER FPGA2 LEDresource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA2 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=boolUSER FPGA3 LEDresource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA3 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="EngineSim.vi" Type="VI" URL="../EngineSim.vi">
					<Property Name="BuildSpec" Type="Str">{538EDFD4-586C-43FD-A1C2-55EA9E165172}</Property>
					<Property Name="configString.guid" Type="Str">{02202DE3-A694-4DD7-AECF-5B60CA45CD59}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=bool{07C239CC-BAE4-4856-BFF7-64C4324E5AB6}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8{0AF9FB6C-B4A6-423C-819A-CD349389EA28}resource=/crio_Knock/AO11;0;WriteMethodType=i16{0FC6B6FC-7829-46D9-ADDD-4DF586F0F7E8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=bool{1437F7DC-E6F7-4AB2-B58E-8D03EAD3CA7E}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8{1C6766E5-1A3C-430D-8326-FB647C9F2FB2}resource=/crio_Knock/AO6;0;WriteMethodType=i16{1DBF33B1-2A26-4EB0-94AD-870680DDE992}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{25EDB220-032D-453D-A786-5AB17F1BF0DB}resource=/crio_Knock/AO2;0;WriteMethodType=i16{26FD48E0-4F9D-4E7C-8B57-CB9F01686579}resource=/crio_Knock/AO8;0;WriteMethodType=i16{2B9E4128-0656-42D9-9B5D-577C10F0DD00}resource=/crio_Knock/AO14;0;WriteMethodType=i16{2BCE6392-8B67-4549-80BB-434FCD7B0A0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=bool{31E7088A-C2A3-40C6-BE3F-C36AACCE97C8}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{32179FED-233C-470D-A71A-D006E4C716BD}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool{395360AE-FC7E-4A4F-8192-94FA439D9497}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E{3EFF009C-9DF1-45FE-9E0F-382F14C61FC5}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=bool{4021BA7F-0DE2-4F42-960B-14A43FB02452}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{44F9204E-A80A-456D-8DC3-3611DE27644C}resource=/crio_Knock/AO7;0;WriteMethodType=i16{4F904FB8-88A3-4986-8B83-745601732776}resource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8{66A5FAC6-E477-4D54-A5CA-F1C0BFF1AA0A}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=bool{67DD4EFE-7DE6-480B-8859-83F0B9020C9A}resource=/crio_Knock/AO1;0;WriteMethodType=i16{6A199E15-06DC-4E53-A876-53D42860FEBB}resource=/crio_Knock/AO4;0;WriteMethodType=i16{6AFA68F2-1CEA-45E4-AF9D-1DBDDEE9221F}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool{6CA1580B-158E-447F-B91B-4A477DD8E5B8}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=bool{770B7E7C-EBD2-4696-BDDB-9032CBA3532C}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool{7E4F35BA-8894-43D5-8CDB-7530479B9C71}resource=/crio_Knock/AO9;0;WriteMethodType=i16{81622B9F-7DD7-47C5-9BF1-DF6A8409716B}resource=/crio_Knock/AO15;0;WriteMethodType=i16{817C474E-AE49-4F88-AE61-EDD84EB653B7}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=bool{8498A9D3-D883-4A4A-A168-DF2121DB20CC}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=bool{87309049-5397-4004-81C6-EBABAB226716}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=bool{882762C2-7F73-4D69-83F6-A25D0460BDA3}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool{90C9D34C-7E8B-4943-A8B7-C277B569BC25}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=bool{944F353F-29B1-400D-8753-C12575C07951}resource=/Chassis Temperature;0;ReadMethodType=i16{9565469F-3D92-4663-9A6E-7702976B0FE0}resource=/crio_Knock/AO3;0;WriteMethodType=i16{966C612D-1E03-45B8-8970-F0EFF0AB6A18}resource=/crio_Knock/AO13;0;WriteMethodType=i16{A5578FC0-59CF-4746-808D-498A3AFCAD98}resource=/crio_Knock/AO12;0;WriteMethodType=i16{A80D0CA0-8C79-4E9A-AF35-0F3E0DEC30ED}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool{AEA6723E-93A2-430B-8017-B8D84E64165E}resource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8{BC12DA06-802A-4DAF-9292-FA208C19779F}[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]{BD6DAD3B-C8C5-4554-8F5A-860028091801}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=bool{C0AF8353-A1BB-496D-91BF-06C927E70CFF}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool{C3CE3325-45B0-4AA1-AE19-912C2138C34D}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool{C4643414-0D6C-4584-9A87-035240459863}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8{C9A4F536-0F4D-4A22-89E4-6E70499FDE38}resource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8{D3302C5B-F15B-4EC5-BA01-2DE162097459}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=bool{DB749568-98D0-4F46-AF6E-261A9499D830}NumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool{E1CAFA73-ED58-4051-95EF-F88DFFDD1083}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=bool{E7FA63C6-7B7A-4083-AB48-3A5621E04F84}resource=/crio_Knock/AO5;0;WriteMethodType=i16{EA12F708-40D2-4AD0-A134-D8875FBF65BE}NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=bool{EBD4BDE2-6DCA-4EE2-B680-CBB6905B611F}resource=/crio_Knock/AO10;0;WriteMethodType=i16{ED7DF807-828C-4F1A-B0E8-16E9CEF5C56A}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{F6BB1360-1C3A-4364-961E-DFC7C1BCDAAE}ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool{FA206391-3454-43A9-BDE2-2B90DFF7AE99}resource=/crio_Knock/AO0;0;WriteMethodType=i16NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E9474/DO0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO0;0;ReadMethodType=bool;WriteMethodType=bool9474/DO1ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO1;0;ReadMethodType=bool;WriteMethodType=bool9474/DO2ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO2;0;ReadMethodType=bool;WriteMethodType=bool9474/DO3ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO3;0;ReadMethodType=bool;WriteMethodType=bool9474/DO4ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO4;0;ReadMethodType=bool;WriteMethodType=bool9474/DO5ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO5;0;ReadMethodType=bool;WriteMethodType=bool9474/DO6ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO6;0;ReadMethodType=bool;WriteMethodType=bool9474/DO7:0ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7:0;0;ReadMethodType=u8;WriteMethodType=u89474/DO7ArbitrationForOutputData=NeverArbitrate;resource=/crio_9474/DO7;0;ReadMethodType=bool;WriteMethodType=bool9474[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9474,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16Fuel/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI0;0;ReadMethodType=boolFuel/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI1;0;ReadMethodType=boolFuel/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI2;0;ReadMethodType=boolFuel/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI3;0;ReadMethodType=boolFuel/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI4;0;ReadMethodType=boolFuel/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5:0;0;ReadMethodType=u8Fuel/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Fuel/DI5;0;ReadMethodType=boolFuel[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Knock/AO0resource=/crio_Knock/AO0;0;WriteMethodType=i16Knock/AO10resource=/crio_Knock/AO10;0;WriteMethodType=i16Knock/AO11resource=/crio_Knock/AO11;0;WriteMethodType=i16Knock/AO12resource=/crio_Knock/AO12;0;WriteMethodType=i16Knock/AO13resource=/crio_Knock/AO13;0;WriteMethodType=i16Knock/AO14resource=/crio_Knock/AO14;0;WriteMethodType=i16Knock/AO15resource=/crio_Knock/AO15;0;WriteMethodType=i16Knock/AO1resource=/crio_Knock/AO1;0;WriteMethodType=i16Knock/AO2resource=/crio_Knock/AO2;0;WriteMethodType=i16Knock/AO3resource=/crio_Knock/AO3;0;WriteMethodType=i16Knock/AO4resource=/crio_Knock/AO4;0;WriteMethodType=i16Knock/AO5resource=/crio_Knock/AO5;0;WriteMethodType=i16Knock/AO6resource=/crio_Knock/AO6;0;WriteMethodType=i16Knock/AO7resource=/crio_Knock/AO7;0;WriteMethodType=i16Knock/AO8resource=/crio_Knock/AO8;0;WriteMethodType=i16Knock/AO9resource=/crio_Knock/AO9;0;WriteMethodType=i16Knock[crioConfig.Begin]crio.Calibration=0,crio.Location=Slot 4,crio.Type=NI 9264,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.HotSwapMode=0,cRIOModule.RsiAttributes=[crioConfig.End]NI 9155/Clk40/falsefalseFPGA_EXECUTION_MODEFPGA_TARGETFPGA_TARGET_CLASSNI_9155FPGA_TARGET_FAMILYVIRTEX5TARGET_TYPEFPGA/[rSeriesConfig.Begin][rSeriesConfig.End]Sleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSpark/DI0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI0;0;ReadMethodType=boolSpark/DI1NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI1;0;ReadMethodType=boolSpark/DI2NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI2;0;ReadMethodType=boolSpark/DI3NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI3;0;ReadMethodType=boolSpark/DI4NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI4;0;ReadMethodType=boolSpark/DI5:0NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5:0;0;ReadMethodType=u8Spark/DI5NumberOfSyncRegistersForReadInProject=Auto;resource=/crio_Spark/DI5;0;ReadMethodType=boolSpark[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9411,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]USER FPGA1 LEDresource=/USER FPGA1 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA1 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA1 Switch;0;ReadMethodType=boolUSER FPGA2 LEDresource=/USER FPGA2 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA2 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA2 Switch;0;ReadMethodType=boolUSER FPGA3 LEDresource=/USER FPGA3 LED;0;ReadMethodType=u8;WriteMethodType=u8USER FPGA3 SwitchNumberOfSyncRegistersForReadInProject=Auto;resource=/USER FPGA3 Switch;0;ReadMethodType=bool</Property>
					<Property Name="NI.LV.FPGA.InterfaceBitfile" Type="Str">C:\Projects\HIL ECU demo 2014\FPGA Code\LVPROJ\FPGA Bitfiles\engine_FPGATarget2_EngineSim_ynbXO238io8.lvbitx</Property>
				</Item>
				<Item Name="Fuel" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 3</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9411</Property>
					<Property Name="cRIOModule.DIO3_0InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.DIO7_4InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.NumSyncRegs" Type="Str">11111111</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{ED7DF807-828C-4F1A-B0E8-16E9CEF5C56A}</Property>
				</Item>
				<Item Name="Knock" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">0</Property>
					<Property Name="crio.Location" Type="Str">Slot 4</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9264</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.HotSwapMode" Type="Str">0</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{BC12DA06-802A-4DAF-9292-FA208C19779F}</Property>
				</Item>
				<Item Name="Spark" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 2</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9411</Property>
					<Property Name="cRIOModule.DIO3_0InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.DIO7_4InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.NumSyncRegs" Type="Str">11111111</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{31E7088A-C2A3-40C6-BE3F-C36AACCE97C8}</Property>
				</Item>
				<Item Name="Dependencies" Type="Dependencies">
					<Item Name="vi.lib" Type="Folder">
						<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
						<Item Name="Engine Simulation Toolkit.lvlib" Type="Library" URL="/&lt;vilib&gt;/NI/Engine Simulation Toolkit (EST)/Engine Simulation Toolkit.lvlib"/>
						<Item Name="lvSimController.dll" Type="Document" URL="/&lt;vilib&gt;/rvi/Simulation/lvSimController.dll"/>
						<Item Name="NI_VS FPGA Support.lvlib" Type="Library" URL="/&lt;vilib&gt;/NI Veristand/FPGA/NI_VS FPGA Support.lvlib"/>
					</Item>
					<Item Name="niFpgaCriticalErrorInLSC.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaCriticalErrorInLSC.vi"/>
					<Item Name="niFpgaEmulationReportErrorSimple.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaEmulationReportErrorSimple.vi"/>
					<Item Name="niFpgaEmulationVisToLoad.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaEmulationVisToLoad.vi"/>
					<Item Name="niFpgaEmulError.ctl" Type="VI" URL="/&lt;vilib&gt;/rvi/DesktopExecutionNode/niFpgaEmulError.ctl"/>
					<Item Name="niFpgaGenCallStack.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/niFpgaGenCallStack.vi"/>
					<Item Name="niFpgaGetClockAttributes.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaGetClockAttributes.vi"/>
					<Item Name="niFpgaGetClockAttributesFromContext.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaGetClockAttributesFromContext.vi"/>
					<Item Name="niFpgaGetScratchAppInstance.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/eio/common/niFpgaGetScratchAppInstance.vi"/>
					<Item Name="niFpgaProcessEmulError.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaProcessEmulError.vi"/>
					<Item Name="niFpgaSctlEmulationGetInTimedLoop.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/Emulation/niFpgaSctlEmulationGetInTimedLoop.vi"/>
					<Item Name="niFpgaSetErrorForExecOnDevCompSimple.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/niFpgaSetErrorForExecOnDevCompSimple.vi"/>
					<Item Name="niFpgaWaitOnOcc.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/interface/common/niFpgaWaitOnOcc.vi"/>
					<Item Name="nirviCleanSpecificError.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/nirviCleanSpecificError.vi"/>
					<Item Name="nirviEmuReportErrorAndStop.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/eio/common/nirviEmuReportErrorAndStop.vi"/>
					<Item Name="nirvififoEmulationCreateLock.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/FIFO/Fifo_Resource/nirvififoEmulationCreateLock.vi"/>
					<Item Name="nirvififoEmulationReleaseLock.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/FIFO/Fifo_Resource/nirvififoEmulationReleaseLock.vi"/>
					<Item Name="nirviFillInErrorInfo.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviFillInErrorInfo.vi"/>
					<Item Name="nirviGetToplevelTsByTargetItem.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/ClientSDK/Core/TimingSources/Configuration/Private/nirviGetToplevelTsByTargetItem.vi"/>
					<Item Name="nirviReportUnexpectedCaseInternalError (Bool).vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviReportUnexpectedCaseInternalError (Bool).vi"/>
					<Item Name="nirviReportUnexpectedCaseInternalError (String).vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviReportUnexpectedCaseInternalError (String).vi"/>
					<Item Name="nirviReportUnexpectedCaseInternalError (U32).vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviReportUnexpectedCaseInternalError (U32).vi"/>
					<Item Name="nirviReportUnexpectedCaseInternalError.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviReportUnexpectedCaseInternalError.vi"/>
					<Item Name="nirviReportUnexpectedCaseInternalErrorHelper.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/errors/nirviReportUnexpectedCaseInternalErrorHelper.vi"/>
					<Item Name="nirviTopLevelTSIsDefaultTag.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/ClientSDK/Core/TimingSources/Configuration/Private/nirviTopLevelTSIsDefaultTag.vi"/>
					<Item Name="nirviTopLevelTSTag.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/ClientSDK/Core/TimingSources/Configuration/Private/nirviTopLevelTSTag.vi"/>
					<Item Name="nirviWaitOnOccurrenceBase.vi" Type="VI" URL="/&lt;vilib&gt;/rvi/occurrence/nirviWaitOnOccurrenceBase.vi"/>
					<Item Name="PWM.ctl" Type="VI" URL="../Typedefs/PWM.ctl"/>
					<Item Name="PWMout wrapper.vi" Type="VI" URL="../PWMout wrapper.vi"/>
				</Item>
				<Item Name="Build Specifications" Type="Build">
					<Item Name="EngineSim" Type="{F4C5E96F-7410-48A5-BB87-3559BC9B167F}">
						<Property Name="AllowEnableRemoval" Type="Bool">false</Property>
						<Property Name="BuildSpecDecription" Type="Str"></Property>
						<Property Name="BuildSpecName" Type="Str">EngineSim</Property>
						<Property Name="Comp.BitfileName" Type="Str">engine1_FPGATarget2_EngineSim_CehFP2qeyZY.lvbitx</Property>
						<Property Name="Comp.CustomXilinxParameters" Type="Str"></Property>
						<Property Name="Comp.MaxFanout" Type="Int">-1</Property>
						<Property Name="Comp.RandomSeed" Type="Bool">false</Property>
						<Property Name="Comp.Version.Build" Type="Int">0</Property>
						<Property Name="Comp.Version.Fix" Type="Int">0</Property>
						<Property Name="Comp.Version.Major" Type="Int">1</Property>
						<Property Name="Comp.Version.Minor" Type="Int">0</Property>
						<Property Name="Comp.VersionAutoIncrement" Type="Bool">false</Property>
						<Property Name="Comp.Xilinx.DesignStrategy" Type="Str">balanced</Property>
						<Property Name="Comp.Xilinx.MapEffort" Type="Str">high(timing)</Property>
						<Property Name="Comp.Xilinx.ParEffort" Type="Str">standard</Property>
						<Property Name="Comp.Xilinx.SynthEffort" Type="Str">normal</Property>
						<Property Name="Comp.Xilinx.SynthGoal" Type="Str">speed</Property>
						<Property Name="Comp.Xilinx.UseRecommended" Type="Bool">true</Property>
						<Property Name="DefaultBuildSpec" Type="Bool">true</Property>
						<Property Name="DestinationDirectory" Type="Path">FPGA Bitfiles</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePath" Type="Path">/C/Projects/HIL ECU demo 2014/FPGA Code/LVPROJ/FPGA Bitfiles/engine_FPGATarget2_EngineSim_ynbXO238io8.lvbitx</Property>
						<Property Name="ProjectPath" Type="Path">/C/Projects/HIL ECU demo/FPGA Code/LVPROJ/engine1.lvproj</Property>
						<Property Name="RelativePath" Type="Bool">true</Property>
						<Property Name="RunWhenLoaded" Type="Bool">false</Property>
						<Property Name="SupportDownload" Type="Bool">true</Property>
						<Property Name="SupportResourceEstimation" Type="Bool">true</Property>
						<Property Name="TargetName" Type="Str">FPGA Target 2</Property>
						<Property Name="TopLevelVI" Type="Ref">/RT PXI Target/Chassis/FPGA Target 2/EngineSim.vi</Property>
					</Item>
				</Item>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
