#ifndef _FUN_H
#define _FUN_H

#include <stdio.h>

#include <memory>
#include <vector>


//SEGY��ͷ:3600�ֽ�
const int TEXT_HEAD_SIZE = 3200; // ASCII ����: 3200�ֽ�(40����¼ x 80 �ֽ�/ÿ����¼)
const int VOLUME_HEAD_SIZE = 400; //������������: 400�ֽ�(3201~3600)

//SEGY��ͷ����: ��: 60����/4�ֽ�����120����/2�ֽ�������240���ֽڣ��������Ƹ�ʽ���
const int TRACE_HEAD_SIZE = 240;

using namespace std;

struct POINTF
{
	double x;
	double y;
};

struct TRAHEAD //SEGY��׼rev1,IEEE FLOATING POINT
{
	int iSLNum;	//1-4	�����ڵĵ�˳���
	int iTSTNum; //5-8	����˳����ţ�ÿ�̴Ŵ���1��ʼ
	int iOriNum;		// 9-12 **ԭʼ��Ұ���¼�ţ��ںţ�
	int iTraNum;  //13-16	ԭʼ��¼�ڵĵ���
	int iSorceNum;	 //17-20	��ը��ţ���ͬһ�ر�λ���ж����¼ʱ�ô˱��
	int iCdpNum;	/* 21-24	CDP�ţ�����¼ΪCDP�����ô˱�� CMP�� */
	int iCdpTra;    //25-28	CDP�ڵ��ţ�ÿ��CDP��1��ʼ
	short nTraId;	   //29-30	����ʶ�룺
	short nVsTra;	   // 31-32	�����˵��Ĵ�ֱ��ϵ�����1-1����2-2������ֱ���ӵ���
	short nHsTra;	  //33-34	�����˵���ˮƽ���ӵ�����1-1����2-2����ˮƽ���ӵ���
	short nDuse;	  //35-36	������;��1-������2-����
	int iOffset;  //37-40	���ڵ㵽���յ�ľ��루�������Ϊ�����������Ϊ��ֵ��ƫ�ƾ�	 
	int gelev; //41-44	���յ�̣߳���ƽ������Ϊ������ƽ������Ϊ��
	int selev;	//45-48	�ڵ�߳�
	int sdepth;	/* 49-52	�ڵ��ڵر��µ���ȣ������� */
	int gdel;	/* 53-56	���յ��׼�߸߳� */
	int sdel;	/* 57-60                    �ڵ��׼�߸߳� */
	int swdep;	/* 61-64	�ڵ�ˮ��*/
	int gwdep;	/* 65-68	���յ�ˮ�� */
	short scalel;//69-70	���ֽ�41-68�����и̺߳����Ӧ�õı���
	short scalco;//1-72	���ֽ�73-88������ȷ��������Ӧ�õı�����
	int  iSourseX;	/* 73-76	�ڵ�����-x       ������굥λΪ������������x��ʾ����- X */
	int  iSourseY;	/* 73-76	�ڵ�����-y       ������굥λΪ������������y��ʾ���ȣ�- Y */
	int  iGroupX;	/* 81-81	���յ�����-x	������Ա�����ֵָʾ�ϻ��������� - X */
	int  iGroupY;	/* 85-88	���յ�����- Y */
	short counit; //89-90	���굥λ��1-���ȣ��׻�ߣ���2-��	
	short wevel;	/* 91-92	�绯���ٶ�*/
	short swevel;	/* 93-94	�绯�����ٶ�*/
	short sut;	/* 95-96	�ڵ㾮��ʱ�� */
	short gut;	/*97-98	���յ㾮��ʱ�� */
	short sstat;	/* 99-100	�ڵ㾲У���� */
	short gstat;	/* 101-102	���յ㾲У����*/
	short tstat; //103-104	Ӧ�õ��ܾ�У����
	short laga; //105-106	�ӳ�ʱ��A��ms�������ʱ���ź���ͷ�����֮�������Ϊ��
	short lagb;	//107-108	�ӳ�ʱ��B��ms���������ɸ�����ʱ���źźͱ�ըԴ��ʱ��
	short delrt; //109-110	�ӳټ�¼ʱ�䣨ms���������ݲ�����ʼʱ��ͱ�ըԴ��ʱ��
	short muts;	/* 111-112	�г���ʼʱ�� */
	short mute;	/* 113-114	�г�����ʱ�� */
	unsigned short uNs; //**�������� 115-116
	unsigned short uRate;//**������us 117-118
	short gain;	/* 119-120	Ұ��������������*/
	short igc;	/* 121-122	�������泣�� */
	short igi;	/* 123-124	������ʼ���棨d B�� */
	short corr;	/* 125-126	��صĵ������1-���ǣ�2-��	*/
	short sfs;	/* 127-128	��ʼɨ��Ƶ��*/
	short sfe;	/* 129-130	��ֹɨ��Ƶ�� */
	short slen;	/* 131-132	ɨ�賤�ȣ�ms�� */
	short styp;	/* 133-134	ɨ������1 = linear 2 = cos-squared 3 = other */
	short stas;	/* 135-136	ɨ�����ʼ���õ�б�³��ȣ�ms�� */
	short stae;	/* 137-138	ɨ�������ʱ�õ�б�³��ȣ�ms�� */
	short tatyp;	/* 139-140	б�����ͣ�1-���ͣ�2-cos2��3-���� */
	short afilf;	/* 141-142	��Ƶ�˲���Ƶ�� */
	short afils;	/* 143-144	��Ƶ�˲���б�� */
	short nofilf;	/* 145-146	�ݲ��˲���Ƶ�� */
	short nofils;	/* 147-148	�ݲ��˲���б�� */
	short lcf;	/*149-150	�ͽ�ֹƵ�� */
	short hcf;	/* 151-152	�߽�ֹƵ�� */
	short lcs;	/* 153-154	�ͽ�ֹб��*/
	short hcs;	/* 155-156	�߽�ֹб��*/
	short year;	//���ݼ�¼���� 157-158
	short day;	//���е����� 159-160
	short hour;	//Сʱ��24Сʱ�ƣ� 161-162
	short minute;	//�� 163-164
	short sec;	//�� 165-166   
	short timbas;	/*167-168	ʱ���׼�룺1-����ʱ�䣬2-��������ʱ�䣬3-���� */
	short trwf;	/* 169-170	�������Ȩ����-��2��-N�η����ã����������Чλ��N=0��1�� */
	short grnors;	/* 171-172	��������λ��1�ļ첨����� */
	short grnofr;	/* 173-174	��ԭʼ��¼�ڣ���1�ļ첨����� */
	short grnlof;	/* 175-176	��ԭʼ��¼�ڣ����һ���ļ첨����� */
	short gaps;	/* 177-178	�����С��ȥ���ļ첨����������� */
	short otrav; //179-180	�ڲ��߿�ʼ�������Խ��б��
#ifdef UNOCAL_SEGY_H  	//��60�ֽ��Զ���
	/* cwp local assignments */
	float d1;	/* sample spacing for non-seismic data */
	float f1;	/* first sample location for non-seismic data */
	float d2;	/* sample spacing between traces */
	float f2;	/* first trace location */
	float ungpow;	/* negative of power used for dynamic			   range compression */
	float unscale;	/* reciprocal of scaling factor to normalize			   range */
	short mark;	/* mark selected traces */	/* UNOCAL local assignments */ 
	short mutb;	/* mute time at bottom (start time)  */			/* bottom mute ends at last sample   */
	float dz;	/* depth sampling interval in (m or ft)  */			/* if =0.0, input are time samples       */
	float fz;	/* depth of first sample in (m or ft)  */
	short n2;	/* number of traces per cdp or per shot */
    short shortpad; /* alignment padding */
	int ntr; 	/* number of traces */
	/* UNOCAL local assignments end */ 
	short unass[8];	/* unassigned */
#else
	/* cwp local assignments */
	float d1;	/* sample spacing for non-seismic data */
	float f1;	/* first sample location for non-seismic data */
	float d2;	/* sample spacing between traces */
	float f2;	/* first trace location */
	float ungpow;	/* negative of power used for dynamic			   range compression */
	float unscale;	/* reciprocal of scaling factor to normaliz   range */
	int ntr; 	/* number of traces */
	short mark;	/* mark selected traces */
    short shortpad; /* alignment padding */
	short unass[14];			   			   
#endif
};

struct VOLHEAD  //SEGY��׼rev1,IEEE FLOATING POINT
{
	int jobid;	/* 3201-3204                ��ҵ��ʶ��  */
	int lino;	 	//*�ߺ�(ÿ��ֻ��һ���ߺ�) 3205-3208
	int reno;		//*��� 3209-3212
	short ntrpr;	//*ÿ�����������ݵ�������ǰ����ǿ��Ҫ�� 3213-3214
    short nart;		//*ÿ�������ĸ�����������ǰ����ǿ��Ҫ�� 3215-3216
	unsigned short hdt; 	//*΢�루us����ʽ�Ĳ����������ǰ����ǿ��Ҫ�� 3217-3218
	unsigned short dto; /* 3219-3220    ΢�루us����ʽ��ԭʼҰ���¼�������*/
	unsigned short hns; //*���ݵ�������������ǰ����ǿ��Ҫ�� 3221-3222
	unsigned short nso; /* ԭʼҰ���¼ÿ���������� */
	short format;//*1=4�ֽ�IBM���� 2=4�ֽڣ����������� 3=2�ֽڣ����������� 4=4�ֽڴ����涨��������ʱ������ʹ�ã�
	//	5=4�ֽ�IEEE������
	//	6=����û��ʹ��
	//	7=����û��ʹ��
	//	8=1�ֽڣ�����������	
	short fold;		//*CDP���Ǵ��� 3227-3228
	short tsort;	//����ѡ�루���������ͣ���-1=������Ӧ���û���չ�ļ�ͷ�ı����н��ͣ�
	//	0=δ֪
	//	1=ͬ��¼��δ��ѡ��
	//	2=CDP����
	//	3=���θ�����������
	//	4=ˮƽ����
	//	5=���ڵ�
	//	6=�����յ�
	//	7=��ƫ�ƾ�
	//	8=�����ĵ�
	//	9=��ת����
	//	ǿ���Ƽ��������͵�����ʹ��
	short vscode;	//3231-3232	��ֱ����룺1-����ϣ�2-������ϣ���������������N-N�����
	short hsfs;	/* 3233-3234	��ʼɨ��Ƶ�� */
	short hsfe;	/* 3235-3236	��ֹɨ��Ƶ�� */
	short hslen;	/* 3237-3238	ɨ�賤�ȣ�ms�� */
	short hstyp; //3239-3240	ɨ�������룺
	short schn;	/* 3241-3242	ɨ��ͨ������ */
	short hstas; //3243-3244	���ʹ��б�£�ɨ�����ʼ���õ�б�³���ms��
	short hstae; //3245-3246	ɨ�����ʱ�õ�б�³��ȣ�ms��
	short htatyp; //3247-3248	б�º��������룺
	short hcorr; //3249-3250	��ص����ݵ���1-���ǣ�2-��
	short bgrcv; //3251-3252	����������ָ���1-�ǣ�2-����
	short rcvm;	 //3253-3254	����ָ�������1-�� 2-AGC 3-������ɢ 4-����
	short mfeet; //  //������λ=1 3255-3256
	short polyt; //3257-3258	�����źż��ԣ�
	short vpol;	//3259-3260	�񶯼����룺�����ź��ӳٿ����ź�
	short hunass[170];	/* unassigned */
};


class CSegy
{
public:
	CSegy();
	~CSegy();
	CSegy(char * csSgyParth);
	bool m_bHasTextHead;
	bool m_bIsEDBCode;
	bool m_bIsBigEndian;

	enum DataFormat
	{
		IBMFLOAT,
		IEEEFLOAT,
		IEEEINT32,
		IEEEINT16,
		IEEEINT8
	};

	const char* ReadTextHead();
	const VOLHEAD &ReadVolumeHead();
	const TRAHEAD &ReadTraceHead(int nIndex=-1);
	const float* ReadTraceData(int nIndex=-1);

	void SwapVolumeHead(VOLHEAD &);
	void SwapTraceHead(TRAHEAD &);
    void OpenFile(char *);

	char m_csFilepath[300];

	void showInfo();


	
private:
	char * csReadFile;//�ļ�·��
	DataFormat m_fmt; //1-��������4�ֽڣ� 2-��������4�ֽڣ� 3-�����涨������4�ֽڣ�
	TRAHEAD m_traHead;
	VOLHEAD m_volHead;
	unsigned long long m_lFileLenth; //�ļ���С

	unsigned  m_nTraNumPerInLine;//ÿ����¼�ĵ���
	int m_nTraceTolNum; //�ܵ���
	int m_nInLineNum; //����
	int m_nXLineNum; //����
	int m_nCurrentTraceNum;
//	int m_nSmpNum;//��������

	POINTF P1,P2,P3,P4;
	long lStartPosition; //���ݿ�ʼ����
	
	char m_szTextInfo[TEXT_HEAD_SIZE]; //EDBC��Ϣ
	char m_szTraceHead[TRACE_HEAD_SIZE];

	int m_nSampleInterval; //�������
	int m_nSampleNum; //��������
	int m_nDataLenth; //���ݳ��� 
	int m_nStrtInLine; //��ʼ�ߺ�
	int m_nStopInLine;//��ֹ�ߺ�
	int m_nStrtXLine;//��ʼ����
	int m_nStopXline;//��ֹ����
	int m_nStrtTime;
	int m_nStopTime;
	int m_nScaleoSet; //��������

	int m_nXCoordLenth; //x���곤��
	int m_nYCoordLenth;//Y���곤��
	int m_nXCoordSet; //x����λ��
	int m_nYCoordSet; //Y����λ��
	int m_nInlineSet; //inlineλ��
	int m_nXlineSet; //xlineλ��
	int m_nInlineLenth; //�ߺų���
	int m_nXLineLenth; //���ų���
	int m_nTotalTraceNum; //�ܵ���
	float m_fXInterval; //x��������
	float m_fYInterval; //y��������
	float m_fTraceInterval; //�����
	float m_fLineInterval; //�߼��

	bool bDataOrdination;
	bool m_bDataWS; //�Ƿ���վ��ʽ
	bool m_bDataIBMFmt; //�Ƿ�IBM������
	bool m_bCoordUserSet;//�Ƿ��û��Զ�������
	bool m_bLineSet; //�Ƿ����ߵ���
	bool m_bCoordSet; //�Ƿ���x,y����
	bool segyRegular;//�Ƿ��ǹ����segy
	bool m_bEBText; //�Ƿ��е�ͷY
	bool m_bOpen;
	
public:
	void closeFile();
	void SetInfo();
	void ScanData();
	void Scan3DData();
    char *GetTextHead();


    //const VOLHEAD &GetVolumeHeader() const;

    VOLHEAD *GetVolumeHead();

	POINTF ScanPerTrace(int num);
	FILE *m_fpr;

};
#endif

#define prinfErr printf
