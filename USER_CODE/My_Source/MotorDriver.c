//#include "..\..\config.h"
//
//
////------------------------------------------------------------------------------
////��������SinMotDri
////��  �ܣ���������Ŀ���������Ͷ���š�Ŀ��λ�á�Ŀ���ٶȼ�������
////��  �룺MotID����ţ�PosĿ��λ�ã�VelĿ���ٶ�
////��  �أ�������
////��  ע��������255-ͨѶ����254-����ų�����Χ��128-�㲥��ַ�����෵�ض��ERROR�ֽ�
////------------------------------------------------------------------------------
//char SinMotDri( char MotID , int Pos , int Vel )
//{
//	 char ParaLen;
//	 char TXDPara[5];
//	 
//	 if( ( MotID > 18 ) || ( MotID < 1 ) ) return 254;//������ų���Χ���򷵻�
//	 
//	 if( Pos >= 1024 ) Pos = 1023;//Ŀ��λ�á�Ŀ���ٶ������С����
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
////��������MotorControl
////��  �ܣ����ƶ���������
////��  �룺*MotorҪ���ƵĶ���ţ�*Posʹ�䵽���λ�ã�*VelĿ���ٶȣ�NumOfMotorҪ���ƵĶ������
////��  �أ��Ƿ�ɹ�
////��  ע��
////------------------------------------------------------------------------------
//char MotorControl(char* Motor,int* Pos,int* Vel,char NumOfMotor)
//{
//	 char Para[72]={0};
//	 char j,PL=0,PH=0,VL=0,VH=0; 
//	 
//	 for(j=0;j<NumOfMotor;j++)
//	 {
//		  if( *(Pos+j) >= 1024 ) *(Pos+j) = 1023;//Ŀ��λ�á�Ŀ���ٶ������С����
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
////��������WriteData
////��  �ܣ����д�Ĵ���ָ��
////��  �룺MotID����ţ�* paraҪд��Ĳ�����ParaLenд������ĳ���
////��  �أ�������
////��  ע��������255-ͨѶ����128-�㲥��ַ�����෵�ض��ERROR�ֽ�
////------------------------------------------------------------------------------
////char WriteData( char MotID , char* para , char ParaLen )
////{
////	 char checksum = 0,i=0;
////	 char RXDBuffer[6];
////	 
////	 RS485TXD;		   //��Ϊ����״̬
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
////	 while( !( UCSR1A & (1<<TXC1) ) );//�ȴ��������
////	 UCSR1A |= (1<<TXC1);
////	 RS485RXD; 		  //���ͽ�����485���ƿ�PA7��Ϊ����״̬
////	 
////	 //---------------------------Read Status Packet--------------------------------
////	 if( 0xFE != MotID )//����Ϊ�㲥��ַ�����ж϶�ȡ��״̬���Ƿ��д���
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
//////��������SyncWrite
//////��  �ܣ�������д�Ĵ���ָ��
//////��  �룺NumOfMot�������*MotID����ţ�LenOfParaÿ�����д�뼸��������
//////	  	  *ParaҪд��Ĳ�����StaAdd��ʼ��ַ
//////��  �أ���
//////��  ע�����������״̬��
//////------------------------------------------------------------------------------
////void SyncWrite(char NumOfMot,char* MotID,char LenOfPara,char* Para,char StaAdd)
////{
////	 char i,j,checksum;
////	 
////	 RS485TXD;		   //��Ϊ����״̬
////	 
////	 U1Trans(0xFF);
////	 U1Trans(0xFF);
////	 U1Trans(0xFE);	//�㲥��ַ
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
////	 while( !( UCSR1A & (1<<TXC1) ) );//�ȴ��������
////	 UCSR1A |= (1<<TXC1);
////	 RS485RXD; 		  //���ͽ�����485���ƿ�PA7��Ϊ����״̬
////}
////
//////------------------------------------------------------------------------------
//////��������StopMotor
//////��  �ܣ��ö����1���ٶ����У�����Ϊֹͣ
//////��  �룺MotID����Ҫֹͣ�Ķ���ţ�NumofMotor����Ҫ���ƵĶ������
//////��  �أ���
//////��  ע�����������״̬��
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
//////��������StopLeg()
//////��  �ܣ�������1���ٶ����У�����Ϊֹͣ
//////��  �룺Num �ڼ�����
//////��  �أ���
//////��  ע�����������״̬��
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
//////��������TorqueOff()
//////��  �ܣ����ȵ�������ʧ��
//////��  �룺Num �ڼ�����
//////��  �أ���
//////��  ע�����������״̬��
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
//////��������TorqueOn()
//////��  �ܣ��ö�����������״̬��
//////��  �룺Num �ڼ�����
//////��  �أ���
//////��  ע�����������״̬��
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
//////��������ReadPos()
//////��  �ܣ��������ǰλ��
//////��  �룺MotID������ţ�
//////��  �أ����λ��
//////------------------------------------------------------------------------------
////int ReadPos(char MotID)
////{
////	char checksum = 0,i=0;
//// 	char RXDBuffer[8];
//// 	int	Result=0;
////	
////	RS485TXD;		   //��Ϊ����״̬
//// 
//// 	//---------------------------Send Instruction Packet---------------------------
////	U1Trans(0xFF);
////	U1Trans(0xFF);
////	U1Trans(MotID);
////	U1Trans(0x04);
////	U1Trans(READ_DATA);
////	U1Trans(0x24);  //�������ǰλ��
////	U1Trans(0x02); 
////	 
////	checksum += ( MotID + 0x04 + READ_DATA + 0x24 + 0x02) ;
//// 	checksum = ~checksum;
//// 
//// 	U1Trans(checksum);
//// 
//// 	//-----------------------------------------------------------------------------
//// 	while( !( UCSR1A & (1<<TXC1) ) );//�ȴ��������
//// 	UCSR1A |= (1<<TXC1);
//// 	RS485RXD; 		  //���ͽ�����485���ƿ�PA7��Ϊ����״̬
//// 
//// 	//---------------------------Read Status Packet--------------------------------
//// 	if( 0xFE != MotID )//����Ϊ�㲥��ַ�����ж϶�ȡ��״̬���Ƿ��д���
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
