//#include "..\..\config.h"
//
//
////------------------------------------------------------------------------------
////函数名：SinMotDri
////功  能：单个舵机的控制命令，发送舵机号、目标位置、目标速度即可行走
////输  入：MotID舵机号，Pos目标位置，Vel目标速度
////返  回：错误字
////备  注：错误字255-通讯错误，254-舵机号超过范围，128-广播地址，其余返回舵机ERROR字节
////------------------------------------------------------------------------------
//char SinMotDri( char MotID , int Pos , int Vel )
//{
//	 char ParaLen;
//	 char TXDPara[5];
//	 
//	 if( ( MotID > 18 ) || ( MotID < 1 ) ) return 254;//若舵机号超范围，则返回
//	 
//	 if( Pos >= 1024 ) Pos = 1023;//目标位置、目标速度最大最小限制
//	 else if( Pos <= 0 ) Pos = 0;
//	 if( Vel >= 1024 ) Pos = 1023;
//	 else if( Vel <= 0 ) Pos = 0;
//	 
//	 //------------------------------Gain the Parameters----------------------------
//	 ParaLen = 5;
//	 TXDPara[0]= 0x1E;
//	 TXDPara[1]= Pos;
//	 TXDPara[2]= Pos >> 8 ;
//	 TXDPara[3]= Vel;
//	 TXDPara[4]= Vel >> 8;
//	 
//	 //-----------------------------Move the ServoMotor----------------------------- 
//	 return WriteData(MotID,TXDPara,ParaLen);
//}
//
////------------------------------------------------------------------------------
////函数名：MotorControl
////功  能：控制多个舵机行走
////输  入：*Motor要控制的舵机号，*Pos使其到达的位置，*Vel目标速度，NumOfMotor要控制的舵机个数
////返  回：是否成功
////备  注：
////------------------------------------------------------------------------------
//char MotorControl(char* Motor,int* Pos,int* Vel,char NumOfMotor)
//{
//	 char Para[72]={0};
//	 char j,PL=0,PH=0,VL=0,VH=0; 
//	 
//	 for(j=0;j<NumOfMotor;j++)
//	 {
//		  if( *(Pos+j) >= 1024 ) *(Pos+j) = 1023;//目标位置、目标速度最大最小限制
//		  else if( *(Pos+j) <= 0 ) *(Pos+j) = 0;
//		  if( *(Vel+j) >= 1024 ) *(Vel+j) = 1023;
//		  else if( *(Vel+j) <= 0 ) *(Vel+j) = 0;
//		 
//		  PL = *(Pos+j);
//		  PH = *(Pos+j) >> 8 ;
//		  VL = *(Vel+j);
//		  VH = *(Vel+j) >> 8 ;
//		 
//		  Para[j*4+0] = PL;
//		  Para[j*4+1] = PH;
//		  Para[j*4+2] = VL;
//		  Para[j*4+3] = VH;
//	 }
//	 SyncWrite(NumOfMotor,Motor,4,Para,0x1E);
//	
//	 return 1;
//}
//
////------------------------------------------------------------------------------
////函数名：WriteData
////功  能：舵机写寄存器指令
////输  入：MotID舵机号，* para要写入的参数，ParaLen写入参数的长度
////返  回：错误字
////备  注：错误字255-通讯错误，128-广播地址，其余返回舵机ERROR字节
////------------------------------------------------------------------------------
////char WriteData( char MotID , char* para , char ParaLen )
////{
////	 char checksum = 0,i=0;
////	 char RXDBuffer[6];
////	 
////	 RS485TXD;		   //改为发送状态
////	 
////	 //---------------------------Send Instruction Packet---------------------------
////	 U1Trans(0xFF);
////	 U1Trans(0xFF);
////	 U1Trans(MotID);
////	 U1Trans(ParaLen+2);
////	 U1Trans(WRITE_DATA);
////	 
////	 for( i = 0 ; i < ParaLen ; i++ )
////	 {
////		  U1Trans( *(para+i) );
////		  checksum += *(para+i);
////	 }
////	 checksum += ( MotID + (ParaLen+2) + WRITE_DATA );
////	 checksum = ~checksum;
////	 
////	 U1Trans(checksum);
////	 
////	 //-----------------------------------------------------------------------------
////	 while( !( UCSR1A & (1<<TXC1) ) );//等待发送完成
////	 UCSR1A |= (1<<TXC1);
////	 RS485RXD; 		  //发送结束后485控制口PA7改为接收状态
////	 
////	 //---------------------------Read Status Packet--------------------------------
////	 if( 0xFE != MotID )//若不为广播地址，则判断读取的状态包是否有错误
////	 {
////		  for( i = 0 ; i < 6 ; i ++ )
////		   RXDBuffer[i] = U1Recei();
////		
////		  if( 0xFF != RXDBuffer[0] ) return 255;
////		  if( 0xFF != RXDBuffer[1] ) return 255;
////		  if( MotID != RXDBuffer[2] ) return 255;
////		  if( 2 != RXDBuffer[3] ) return 255;
////		  if( 0 != RXDBuffer[4] ) return 255;
////		  if( 0xFF != (RXDBuffer[2]+RXDBuffer[3]+RXDBuffer[4]+RXDBuffer[5]) ) return 255;
////		 
////		  return RXDBuffer[4];
////	 }
////	 else
////	  return 128;
////}
////
//////------------------------------------------------------------------------------
//////函数名：SyncWrite
//////功  能：多个舵机写寄存器指令
//////输  入：NumOfMot舵机数，*MotID舵机号，LenOfPara每个舵机写入几个参数，
//////	  	  *Para要写入的参数，StaAdd起始地址
//////返  回：无
//////备  注：此命令不返回状态包
//////------------------------------------------------------------------------------
////void SyncWrite(char NumOfMot,char* MotID,char LenOfPara,char* Para,char StaAdd)
////{
////	 char i,j,checksum;
////	 
////	 RS485TXD;		   //改为发送状态
////	 
////	 U1Trans(0xFF);
////	 U1Trans(0xFF);
////	 U1Trans(0xFE);	//广播地址
////	 U1Trans( ( LenOfPara + 1 ) * NumOfMot + 4 );//length
////	 U1Trans(SYNC_WRITE);//instruction
////	  
////	 U1Trans(StaAdd);
////	 U1Trans(LenOfPara);
////	 checksum = 0xFE + ( ( LenOfPara + 1 ) * NumOfMot + 4 ) + SYNC_WRITE  + StaAdd + LenOfPara ;
////	 for( i = 0 ; i < NumOfMot ; i++ )
////	 {
////		  U1Trans( *(MotID+i) );
////		  checksum += *(MotID+i);
////		  for( j = 0 ; j < LenOfPara ; j++)
////		  {
////			   U1Trans( *(Para + i*LenOfPara + j ) );
////			   checksum += *(Para + i*LenOfPara + j );
////		  }
////	 }
////	 U1Trans(~checksum); 
////	 
////	 //-----------------------------------------------------------------------------
////	 while( !( UCSR1A & (1<<TXC1) ) );//等待发送完成
////	 UCSR1A |= (1<<TXC1);
////	 RS485RXD; 		  //发送结束后485控制口PA7改为接收状态
////}
////
//////------------------------------------------------------------------------------
//////函数名：StopMotor
//////功  能：让舵机以1的速度运行，近似为停止
//////输  入：MotID是需要停止的舵机号，NumofMotor是需要控制的舵机个数
//////返  回：无
//////备  注：此命令不返回状态包
//////------------------------------------------------------------------------------
////void StopMotor(char* MotID, char NumOfMotor)
////{
////	 char Para[36]; 
////	 int j; 
////	  for(j=0;j<NumOfMotor;j++)
////	 {
////		  Para[j*2+0] = 1;
////		  Para[j*2+1] = 0;
////	 }
////	 SyncWrite(NumOfMotor,MotID,2,Para,0x20);
////}
////
//////------------------------------------------------------------------------------
//////函数名：StopLeg()
//////功  能：让腿以1的速度运行，近似为停止
//////输  入：Num 第几条腿
//////返  回：无
//////备  注：此命令不返回状态包
//////------------------------------------------------------------------------------
////void StopLeg(char Num)
////{
////	char MotID[3];
////	int i;
////	
////	for(i=0; i<3; i++)
////	{
////		MotID[i] = Num*3-2+i;
////	}	
////	StopMotor(MotID, 3);
////}
////
//////------------------------------------------------------------------------------
//////函数名：TorqueOff()
//////功  能：让腿的力矩消失，
//////输  入：Num 第几条腿
//////返  回：无
//////备  注：此命令不返回状态包
//////------------------------------------------------------------------------------
////void TorqueOff(char Num)
////{
////	char Para[3], MotID[3]; 
//// 	int j; 
////  	for(j=0; j<3; j++)
//// 	{
//// 		 Para[j] = 0;
////		 MotID[j] = Num*3+j-2;
////  	}
////	
//// 	SyncWrite(Num, MotID, 1, Para, 0x18);
////}
////
//////------------------------------------------------------------------------------
//////函数名：TorqueOn()
//////功  能：让舵机锁死在这个状态，
//////输  入：Num 第几条腿
//////返  回：无
//////备  注：此命令不返回状态包
//////------------------------------------------------------------------------------
////void TorqueOn(char Num)
////{
////	char Para[3], MotID[3]; 
//// 	int j; 
////  	for(j=0; j<3; j++)
//// 	{
//// 		 Para[j] = 1;
////		 MotID[j] = Num*3+j-2;
////  	}
////	
//// 	SyncWrite(Num, MotID, 1, Para, 0x18);
////}
////
//////------------------------------------------------------------------------------
//////函数名：ReadPos()
//////功  能：读舵机当前位置
//////输  入：MotID（舵机号）
//////返  回：舵机位置
//////------------------------------------------------------------------------------
////int ReadPos(char MotID)
////{
////	char checksum = 0,i=0;
//// 	char RXDBuffer[8];
//// 	int	Result=0;
////	
////	RS485TXD;		   //改为发送状态
//// 
//// 	//---------------------------Send Instruction Packet---------------------------
////	U1Trans(0xFF);
////	U1Trans(0xFF);
////	U1Trans(MotID);
////	U1Trans(0x04);
////	U1Trans(READ_DATA);
////	U1Trans(0x24);  //读舵机当前位置
////	U1Trans(0x02); 
////	 
////	checksum += ( MotID + 0x04 + READ_DATA + 0x24 + 0x02) ;
//// 	checksum = ~checksum;
//// 
//// 	U1Trans(checksum);
//// 
//// 	//-----------------------------------------------------------------------------
//// 	while( !( UCSR1A & (1<<TXC1) ) );//等待发送完成
//// 	UCSR1A |= (1<<TXC1);
//// 	RS485RXD; 		  //发送结束后485控制口PA7改为接收状态
//// 
//// 	//---------------------------Read Status Packet--------------------------------
//// 	if( 0xFE != MotID )//若不为广播地址，则判断读取的状态包是否有错误
//// 	{
////  		for( i = 0 ; i < 8 ; i ++ )
////   			RXDBuffer[i] = U1Recei();
////
////  		if( 0xFF != RXDBuffer[0] ) return 1;
////  		if( 0xFF != RXDBuffer[1] ) return 2;
////  		if( MotID != RXDBuffer[2] ) return 3;
////  		if( 4 != RXDBuffer[3] ) return 4;
////  		if( 0 != RXDBuffer[4] ) return 5;
////  		if( 0xFF != (RXDBuffer[2]+RXDBuffer[3]+RXDBuffer[4]+RXDBuffer[5]+RXDBuffer[6]+RXDBuffer[7]) ) return 6;
//// 
//// 		Result = (int) RXDBuffer[6];
////		Result = Result << 8;
////		Result += (int) RXDBuffer[5];
////  		return Result;
//// 	}
//// 	else
////  		return 128;
////}
