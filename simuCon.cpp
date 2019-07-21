#pragma execution_character_set("utf-8")
#include "simuCon.h"
#include <string.h>
using namespace std;
int  entrence = 3;//����� 
stringstream str;
double  a[ENTRENCE][TIME] = { 0 };		//���ض�ȡtxt�����ݣ��Զ����������ʱ��һСʱ�� 
double  lambda_sum[TIME] = { 0 };
int  	timemax;						//�����ļ������֪�ʱ�� 
double  s_list[ENTRENCE][TIME] = { 0 };	//��ͬʱ�̲�ͬ��ڶ�Ӧ��sֵ��չ�������������� 
double  x_list[TIME] = { 0 }; 			//��ͬʱ��չ����ÿ���˿���ͣ�������ʱ�� 
double  l_queue[ENTRENCE][TIME] = { 0 };//��ͬʱ�̲�ͬ��ڶ�Ӧ��lqֵ ��ƽ���Ŷ������� 
double  w_queue[ENTRENCE][TIME] = { 0 };//��ͬʱ�̲�ͬ��ڶ�Ӧ��wqֵ ��ƽ���ȴ�ʱ�䣩 
double  lq_sum[TIME] = { 0 };			//һ��ʱ����������ܵ�lqֵ ��ƽ���Ŷ������� 
double  wq_sum[TIME] = { 0 };			//һ��ʱ����������ܵ�wqֵ ��ƽ���ȴ�ʱ�䣩 
double  l_queue_pre[ENTRENCE][TIME] = { 0 };//����ǰ��ͬʱ�̲�ͬ��ڶ�Ӧ��lqֵ ��ƽ���Ŷ������� 
double  w_queue_pre[ENTRENCE][TIME] = { 0 };//����ǰ��ͬʱ�̲�ͬ��ڶ�Ӧ��wqֵ ��ƽ���ȴ�ʱ�䣩 
double  lq_sum_pre[TIME] = { 0 };			//����ǰһ��ʱ����������ܵ�lqֵ ��ƽ���Ŷ������� 
double  wq_sum_pre[TIME] = { 0 };			//����ǰһ��ʱ����������ܵ�wqֵ ��ƽ���ȴ�ʱ�䣩 
double s = 0;//չ������������ 
double xnum = 1;//ƽ��ÿ����ͣ��Сʱ�� 
double temp[ENTRENCE] = { 0 };
int order[ENTRENCE] = { 0 };

int timelimit = 0;

simuCon::simuCon(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("ģ��ܿ�");
	this->setFixedSize(this->width(), this->height());
	this->setWindowIcon(QIcon("image/head.png"));
	intval = new QIntValidator(0, 1000, this);
	intval_2 = new QIntValidator(10, 200, this);
	ui.staytime->setValidator(intval);
	ui.peoplenum->setValidator(intval_2);
}

simuCon::~simuCon()
{
}

void simuCon::getNum(int n) {
	num = n;
}



double factorial(double n) {//����׳� 
	if (n == 0)return 1;
	return  n * factorial(n - 1);
}
void sortIndex(int j) {//����С�����˳��ÿһʱ��(j��ͬ)��a[i][j]����ںţ�i��˳�򱣴���order������ ����������s_self���жϴ��� 
	for (int i = 0; i < entrence; i++) {//��һ�д���temp 
		temp[i] = a[i][j];
	}
	for (int k = 0; k < entrence; k++) {
		double min = temp[0];
		int t = 0;
		for (int i = 1; i < entrence; i++) {
			if (temp[i] < min) {
				min = temp[i];
				t = i;
			}
		}
		temp[t] = _MAX;
		order[k] = t;
	}
}
__int64 __NaN = 0xFFF8000000000000, __Infinity = 0x7FF0000000000000, __Neg_Infinity = 0xFFF0000000000000;
const double NaN = *((double *)&__NaN), Infinity = *((double *)&__Infinity), Neg_Infinity = *((double *)&__Neg_Infinity);

bool IsNaN(double dat)
{
	__int64 & ref = *(__int64 *)&dat;
	return (ref & 0x7FF0000000000000) == 0x7FF0000000000000 && (ref & 0xfffffffffffff) != 0;
}

void init() {
	for (int i = 1; i <= entrence; i++) {
		stringstream str;
		str << "C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/txt/" << i << ".txt";
		ifstream infile(str.str(), ios::in | ios::out | ios::binary);
		if (!infile.is_open()) {
			//	cout << "file open fail" << endl;
			return;
		}
		string lin;
		int row = 0;
		while ( getline(infile, lin) && timemax < timelimit) {
			stringstream ss2;//ע�������ͷ�ļ��� #include<sstream>
			ss2 << lin;
			while (ss2) {
				int b;
				ss2 >> b;
				a[i][row] = (double)b;
			}
			row++;
		}
		if ( timemax < row  )
				timemax = row;
		if (timemax > timelimit)
			timemax = timelimit;
		infile.close();
	}
	//--------��ʼ��ÿ��ʱ�̣�ÿ����ڵ��������� s_list ---------
	for (int i = 0; i < entrence; i++) {
		for (int j = 0; j < timemax; j++) {
			lambda_sum[j] += a[i][j];//����ÿ��ʱ���������� 
		}
	}

	//ע�⣺���ĳһ����ڵ�lambdaֵ��Ϊ�㣬�����ڵ�Sֵ��������� 
	for (int j = 0; j < timemax; j++) {
		double s_copy = s;
		sortIndex(j);
		for (int i = 0; i < entrence; i++) {
			if (lambda_sum[j] != 0) {
				s_list[order[i]][j] = round(s_copy*a[order[i]][j] / lambda_sum[j]);
				if (s_list[order[i]][j] == 0 && a[order[i]][j] != 0) {
					s_list[order[i]][j] = 1;//���ĳһ����ڵ�lambdaֵ��Ϊ�㣬���������ڵ�SֵΪ�㣬������Ϊ1 
				}
				s_copy -= s_list[order[i]][j];
				lambda_sum[j] -= a[order[i]][j];
			}
		}
	}


	//--------��ʼ��ÿ��ʱ�̵��ͣ��ʱ�� x_list ---------
	for (int i = 0; i < timemax; i++) {
		x_list[i] = xnum;
	}
}

void subCalRight(int i, int j) {
	double lambda = a[i][j];
	double s_self = s_list[i][j];

	double mu = 1.0 / x_list[j];
	double ro = lambda / mu;
	double ros = ro / s_self;
	double sum1 = 0;

	for (double l = 0; l <= s_self - 1; l++)
		sum1 = sum1 + pow(ro, l) / factorial(l);
	double sum2 = pow(ro, s_self) / factorial(s_self) / (1 - ros);
	double p0 = 1.0 / (sum1 + sum2);
	double p = pow(ro, s_self)*p0 / factorial(s_self) / (1 - ros);
	double Lq = p * ros / (1 - ros);
	double L = Lq + ro;
	double W = L / lambda;
	double Wq = Lq / lambda;
	l_queue[i][j] = Lq;
	w_queue[i][j] = Wq;

}
void subCal_pre(int i, int j) {
	double lambda = a[i][j];
	double s_self = s_list[i][j];

	double mu = 1.0 / x_list[j];
	double ro = lambda / mu;
	double ros = ro / s_self;
	double sum1 = 0;


	for (double l = 0; l <= s_self - 1; l++)
		sum1 = sum1 + pow(ro, l) / factorial(l);
	double sum2 = pow(ro, s_self) / factorial(s_self) / (1 - ros);
	double p0 = 1.0 / (sum1 + sum2);
	double p = pow(ro, s_self)*p0 / factorial(s_self) / (1 - ros);
	double Lq = p * ros / (1 - ros);
	double L = Lq + ro;
	double W = L / lambda;
	double Wq = Lq / lambda;
	l_queue_pre[i][j] = Lq;
	w_queue_pre[i][j] = Wq;

}

void reCal(int i, int j) {
	double lambda = a[i][j];
	double s_self = s_list[i][j];
	if (s_self == 0 || lambda == 0) {
		l_queue[i][j] = lambda;
		w_queue[i][j] = 0;
		return;
	}
	subCalRight(i, j);
}
//////////////////////////////////////////////////////��ʾ�ܿؽ���////////////////////////////
void subCalError(int i, int j) {

	double lambda = a[i][j];
	double s_self = s_list[i][j];
	str << "��" << i << "����� ��" << j << "ʱ��" << "����Ӧ�󣡽����Զ�����ͣ��ʱ��/�Ŷ�ʱ�����������㹩���ϵ��\n";
	double mu_self = ceil(lambda / s_self) + epsilon;
	double x_self = 1.0 / mu_self;
	if (x_self < x_lowest) {
		str << "\t��" << i << "����� ��" << j << "ʱ������̫�࣬����ϵͳ�������������˹�����������\n";
	}
	else {
		str << "\t�Զ�����ͣ��ʱ��/�Ŷ�ʱ������Ϊ" << x_self << "ʱ��\n";
		x_list[j] = x_self;
		for (int k = 0; k <= i; k++)
			reCal(k, j);//�Ը�ʱ��֮ǰ�����������ڽ������¼��� 
	}

}
////////////////////////////////////////////////////////////////////////////////

void cal_post() {
	for (int time = 0; time < timemax; time++) {
		for (int n = 0; n < entrence; n++) {
			double mu = 1.0 / x_list[time];
			double lambda = a[n][time];
			double s_self = s_list[n][time];
			if (lambda == 0 || s_self == 0) {
				//cout << "��" << n << "����� ��" << time << "ʱ��û�����Ŷӣ��رգ�" << endl;
				l_queue[n][time] = lambda;
				w_queue[n][time] = 0;
			}
			else if (lambda >= mu * s_self) {//����Ӧ�� 
				subCalError(n, time);//�޸Ĳ���������ݼ���ɿ��Ľ��
			}
			else {//�������� 
				subCalRight(n, time);//����ȷ�����ݼ���ɿ��Ľ��
			}
		}
	}
}

void cal_pre() {
	for (int time = 0; time < timemax; time++) {
		for (int n = 0; n < entrence; n++) {
			double mu = 1.0 / x_list[time];
			double lambda = a[n][time];
			double s_self = s_list[n][time];
			if (lambda == 0 || s_self == 0) {
				//cout << "��" << n << "����� ��" << time << "ʱ��û�����Ŷӣ��رգ�" << endl;
				l_queue_pre[n][time] = lambda;
				w_queue_pre[n][time] = 0;
			}
			subCal_pre(n, time);//����ȷ�����ݼ���ɿ��Ľ��
		}
	}
}
void merge() {
	for (int i = 0; i < timemax; i++) {
		for (int j = 0; j < entrence; j++) {
			lq_sum[i] += l_queue[j][i];
			wq_sum[i] += w_queue[j][i];
		}
	}
}
void merge_pre() {
	for (int i = 0; i < timemax; i++) {
		for (int j = 0; j < entrence; j++) {
			lq_sum_pre[i] += l_queue_pre[j][i];
			wq_sum_pre[i] += w_queue_pre[j][i];
		}
	}
}

void huatu(double *a, int row, string name) {

	cv::Mat img = cv::Mat::zeros(cv::Size(800, 600), CV_8UC3);
	img.setTo(255);              // ������ĻΪ��ɫ
	  //��ֱ��
	line(img, cv:: Point(50, 550), cv::Point(700, 550), cv::Scalar(0, 0, 0), 1);
	line(img, cv::Point(50, 550), cv::Point(50, 50), cv::Scalar(0, 0, 0), 1);
	//����
	int i = 0;
	int j = 55;
	double k = 550;
	while (i < row) {
		double temp = a[i];
		if (a[i] < 0) {
			temp = -a[i];
		}
		if (IsNaN(a[i])) {
			temp = 0;
		}
		k = k - (temp * 25);
		cv::Point p(j, k);
		if (IsNaN(a[i]))
			circle(img, p, 2, cv::Scalar(0, 0, 255), -1);  // ���뾶Ϊ1��Բ(���㣩
		else if (a[i] >= 0)
			circle(img, p, 2, cv::Scalar(0, 255, 0), -1);  // ���뾶Ϊ1��Բ(���㣩
		else if (a[i] < 0)
			circle(img, p, 2, cv::Scalar(0, 0, 255), -1);  // ���뾶Ϊ1��Բ(���㣩

		j += 10;
		i++;
		k = 550;
	}
	//ɢ�㡣��������������������������
	int sandian = 1;
	int sj = 65;
	int sj1;
	double sk = 550;
	double sk1 = 550;
	while (sandian < row) {
		double temp0 = a[sandian - 1];
		if (a[sandian - 1] < 0) {
			temp0 = -a[sandian - 1];
		}
		if (IsNaN(a[sandian - 1])) {
			temp0 = 0;
		}
		double temp1 = a[sandian];
		if (a[sandian] < 0) {
			temp1 = -a[sandian];
		}
		if (IsNaN(a[sandian])) {
			temp1 = 0;
		}
		sk = sk - (temp1 * 25);
		sk1 = sk1 - (temp0 * 25);
		sj1 = sj - 10;
		cv::Point sp(sj, sk);
		cv::Point sp1(sj1, sk1);
		line(img, sp, sp1, cv::Scalar(0, 255, 255), 1);
		sj += 10;
		sandian++;
		sk = 550;
		sk1 = 550;
	}
	//....................................
	int i1 = 0;
	int zuobiao = 0;
	int yzuobiao = 555;
	while (i1 <= 10) {
		char disW[50];
		sprintf_s(disW, "%d", zuobiao);
		cv::putText(img, disW, cv::Point(20, yzuobiao), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(0, 0, 0), 1, 8);
		zuobiao += 2;
		yzuobiao -= 50;
		i1++;
	}
	int i2 = 0;
	int zuobiao1 = 0;
	int xzuobiao = 45;
	while (i2 <= 13) {
		char disW[50];
		sprintf_s(disW, "%d", zuobiao1);
		cv::putText(img, disW, cv::Point(xzuobiao, 570), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, cv::Scalar(0, 0, 0), 1, 8);
		zuobiao1 += 2;
		xzuobiao += 50;
		i2++;
	}
	string  imgname = name + ".jpg";
	imwrite("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/tiaokongphoto/"+imgname, img);                     //�������ͼλ��
}

void huatuByEntrence(double a[][TIME], int row, string name, int n) {
	stringstream ss;
	ss  << n + 1  << name;
	huatu(a[n], row, ss.str());
}
void simuCon::ShowRes() {
  //entrence = num;
	int people, time,taltime;
	people = ui.peoplenum->text().toInt();
	s = people;
	time = ui.staytime->text().toInt();
	xnum = time;
	taltime = ui.timenum->text().toInt();
	timelimit = taltime;
	init();	//���ļ� ��ʼ��
	cal_pre();	//���� 
	merge_pre();//�ϲ� 
	huatu(lq_sum_pre, timemax, "0pep");
	huatu(wq_sum_pre, timemax, "0time");
	cal_post();	//���� 
	merge();//�ϲ� 
	huatu(lq_sum, timemax, "0afterpep");
	huatu(wq_sum, timemax, "0aftertime");
	for (int pnum = 1; pnum <= 3; pnum++) {
		huatuByEntrence(l_queue_pre, timemax, "pep", pnum-1 );
		huatuByEntrence(l_queue, timemax, "afterpep", pnum-1 );
		huatuByEntrence(w_queue_pre, timemax, "time", pnum - 1);
		huatuByEntrence(w_queue, timemax, "aftertime", pnum - 1);
	}
	conmes = new ConMessage();
	conmes->gettiao(str.str());
	conmes->show();
	
}
