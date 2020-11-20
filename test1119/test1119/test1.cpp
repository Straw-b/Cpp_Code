#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
int main()
{
	FILE* pf = fopen("1.txt", "wb"); // 二进制写
	if (NULL == pf)
	{
		exit(0);
	}

	// 二进制格式来写文件
	//int a = 12345678;
	//fwrite(&a, sizeof(a), 1, pf); // 二进制方式写进去
	//char ch = -1;
	//fwrite(&ch, 1, 1, pf);

	// 文本方式写文件
	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10); // 整形转字符串，第三个参数是多少进制
	fwrite(sz, 1, strlen(sz), pf);

	char ch = -1;
	memset(sz, 0, 32);
	_itoa(ch, sz, 10);
	fwrite(sz, 1, strlen(sz), pf);
	
	fclose(pf);
	return 0;
}
#endif




#if 0
#include <fstream>

// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
		// 这里会发现IO流读整形比C语言那套就简单多了，
		// C 语言得先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // 配置文件
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;

	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
#endif




#if 0
int main()
{
	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10);// 整形转字符串

	memset(sz, 0, 32);
	sprintf(sz, "%d", a);// 格式化
	return 0;
}
#endif




#include <sstream>

#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;

	string str;
	ss >> str;
	string ret = ss.str();
	cout << ret << endl;

	ss.clear(); // 清空只修改状态
	ss.str(""); // 设置空的字符串
	double d = 12.34;
	ss << d;
	ss >> str;

	ret = ss.str();
	cout << ret << endl;
	return 0;
}
#endif




#if 0
int main()
{
	stringstream ss; // 字符串拼接
	ss << "hello";
	ss << "   ";
	ss << "world!!!";

	string s;
	s = ss.str();
	cout << s << endl;
	return 0;
}
#endif




#if 0
int main()
{
	unsigned long long a = 0xffffffffffffffff;
	cout << a << endl;
	return 0;
}
#endif




#if 0
int main()
{
	stringstream sstream;
	// 将多个字符串放入 sstream 中
	sstream << "first" << " " << "string,";
	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;

	// 清空 sstream
	sstream.str(""); // 将底层string对象设置为" "空字符串
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
	return 0;
}
#endif

