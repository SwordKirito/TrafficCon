#pragma execution_character_set("utf-8")
#include "simuCon.h"
#include <string.h>
using namespace std;
int  entrence = 3;//入口数 
stringstream str;
double  a[ENTRENCE][TIME] = { 0 };		//承载读取txt的数据（自定义入口数，时长一小时） 
double  lambda_sum[TIME] = { 0 };
int  	timemax;						//根据文件输入得知最长时间 
double  s_list[ENTRENCE][TIME] = { 0 };	//不同时刻不同入口对应的s值（展厅可容纳人数） 
double  x_list[TIME] = { 0 }; 			//不同时刻展厅内每个人可以停留的最大时间 
double  l_queue[ENTRENCE][TIME] = { 0 };//不同时刻不同入口对应的lq值 （平均排队人数） 
double  w_queue[ENTRENCE][TIME] = { 0 };//不同时刻不同入口对应的wq值 （平均等待时间） 
double  lq_sum[TIME] = { 0 };			//一个时刻所有入口总的lq值 （平均排队人数） 
double  wq_sum[TIME] = { 0 };			//一个时刻所有入口总的wq值 （平均等待时间） 
double  l_queue_pre[ENTRENCE][TIME] = { 0 };//调控前不同时刻不同入口对应的lq值 （平均排队人数） 
double  w_queue_pre[ENTRENCE][TIME] = { 0 };//调控前不同时刻不同入口对应的wq值 （平均等待时间） 
double  lq_sum_pre[TIME] = { 0 };			//调控前一个时刻所有入口总的lq值 （平均排队人数） 
double  wq_sum_pre[TIME] = { 0 };			//调控前一个时刻所有入口总的wq值 （平均等待时间） 
double s = 0;//展厅可容纳人数 
double xnum = 1;//平均每个人停留小时数 
double temp[ENTRENCE] = { 0 };
int order[ENTRENCE] = { 0 };

int timelimit = 0;

simuCon::simuCon(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("模拟管控");
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



double factorial(double n) {//计算阶乘 
	if (n == 0)return 1;
	return  n * factorial(n - 1);
}
void sortIndex(int j) {//按由小到大的顺序将每一时刻(j相同)的a[i][j]的入口号（i）顺序保存在order数组中 ，用来避免s_self的判断错误 
	for (int i = 0; i < entrence; i++) {//将一行存入temp 
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
			stringstream ss2;//注意这个的头文件是 #include<sstream>
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
	//--------初始化每个时刻，每个入口的最大承受量 s_list ---------
	for (int i = 0; i < entrence; i++) {
		for (int j = 0; j < timemax; j++) {
			lambda_sum[j] += a[i][j];//计算每个时刻总来人量 
		}
	}

	//注意：如果某一个入口的lambda值不为零，则该入口的S值必须大于零 
	for (int j = 0; j < timemax; j++) {
		double s_copy = s;
		sortIndex(j);
		for (int i = 0; i < entrence; i++) {
			if (lambda_sum[j] != 0) {
				s_list[order[i]][j] = round(s_copy*a[order[i]][j] / lambda_sum[j]);
				if (s_list[order[i]][j] == 0 && a[order[i]][j] != 0) {
					s_list[order[i]][j] = 1;//如果某一个入口的lambda值不为零，而计算该入口的S值为零，则设置为1 
				}
				s_copy -= s_list[order[i]][j];
				lambda_sum[j] -= a[order[i]][j];
			}
		}
	}


	//--------初始化每个时刻的最长停留时间 x_list ---------
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
//////////////////////////////////////////////////////提示管控建议////////////////////////////
void subCalError(int i, int j) {

	double lambda = a[i][j];
	double s_self = s_list[i][j];
	str << "第" << i << "号入口 在" << j << "时刻" << "供不应求！进行自动调整停留时间/排队时间上限以满足供需关系！\n";
	double mu_self = ceil(lambda / s_self) + epsilon;
	double x_self = 1.0 / mu_self;
	if (x_self < x_lowest) {
		str << "\t第" << i << "号入口 在" << j << "时刻人数太多，超出系统承受能力，请人工限制人数！\n";
	}
	else {
		str << "\t自动调整停留时间/排队时间上限为" << x_self << "时长\n";
		x_list[j] = x_self;
		for (int k = 0; k <= i; k++)
			reCal(k, j);//对该时刻之前计算的其他入口进行重新计算 
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
				//cout << "第" << n << "号入口 在" << time << "时刻没有人排队，关闭！" << endl;
				l_queue[n][time] = lambda;
				w_queue[n][time] = 0;
			}
			else if (lambda >= mu * s_self) {//供不应求 
				subCalError(n, time);//修改不满足的数据计算可靠的结果
			}
			else {//供过于求 
				subCalRight(n, time);//由正确的数据计算可靠的结果
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
				//cout << "第" << n << "号入口 在" << time << "时刻没有人排队，关闭！" << endl;
				l_queue_pre[n][time] = lambda;
				w_queue_pre[n][time] = 0;
			}
			subCal_pre(n, time);//由正确的数据计算可靠的结果
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
	img.setTo(255);              // 设置屏幕为白色
	  //画直线
	line(img, cv:: Point(50, 550), cv::Point(700, 550), cv::Scalar(0, 0, 0), 1);
	line(img, cv::Point(50, 550), cv::Point(50, 50), cv::Scalar(0, 0, 0), 1);
	//画点
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
			circle(img, p, 2, cv::Scalar(0, 0, 255), -1);  // 画半径为1的圆(画点）
		else if (a[i] >= 0)
			circle(img, p, 2, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点）
		else if (a[i] < 0)
			circle(img, p, 2, cv::Scalar(0, 0, 255), -1);  // 画半径为1的圆(画点）

		j += 10;
		i++;
		k = 550;
	}
	//散点。。。。。。。。。。。。。。
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
	imwrite("C:/Users/Sword.Kirito/source/repos/TrafficCon/TrafficCon/tiaokongphoto/"+imgname, img);                     //存放折线图位置
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
	init();	//读文件 初始化
	cal_pre();	//计算 
	merge_pre();//合并 
	huatu(lq_sum_pre, timemax, "0pep");
	huatu(wq_sum_pre, timemax, "0time");
	cal_post();	//计算 
	merge();//合并 
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
