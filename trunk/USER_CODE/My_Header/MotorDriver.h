//#ifndef MOTORDRIVER
//#define MOTORDRIVER
//
////----------------------ServoMotorInstruction----------------------
//#define PPING 		0x01
//#define READ_DATA 	0x02
//#define WRITE_DATA 	0x03
//#define REG_WRITE 	0x04
//#define ACTION 		0x05
//#define RESET 		0x06
//#define SYNC_WRITE 	0x83
////-----------------------------------------------------------------
//
//char SinMotDri( char MotID, int Pos, int Vel );
//char WriteData( char MotID, char* para, char ParaLen );
//void SyncWrite(char NumOfMot, char* MotID, char LenOfPara, char* Para, char StaAdd);
//char MotorControl(char* Motor, int* Pos, int* Vel, char NumOfMotor);
//void StopMotor(char* MotID, char NumOfMotor);
//void StopLeg(char Num);
//void TorqueOff(char Num);
//void TorqueOn(char Num);
//int ReadPos(char MotID);
//
//#endif
