#include <alibabacloud/oss/OssClient.h>
#include <string>
using namespace std;
struct OSSInfo{
    string AccessKeyID = "LTAI5t9pkMuMpBvLwm64yyT4";
    string AccessKeySecret = "Oy7LrcEKmbygzLjO7Edy49kqRpjOx2";
    string EndPoint = "oss-cn-wuhan-lr.aliyuncs.com";
    string Bucket = "62niqiu-test";
}; // OSSInfo类里面存储了用户信息
int main(){
    AlibabaCloud::OSS::InitializeSdk(); //初始化
    OSSInfo info;
    // ossclient 类是最重要的类
    AlibabaCloud::OSS::ClientConfiguration conf; // 默认构造一个clientConfiguration
    AlibabaCloud::OSS::OssClient client(info.EndPoint,info.AccessKeyID,info.AccessKeySecret,conf);//构造一个ossClient对象
    AlibabaCloud::OSS::PutObjectOutcome outcome = client.PutObject(info.Bucket,"dir1/2.txt","3.txt");
    if (outcome.isSuccess()){
        cout << "Success!\n";
    }
    else{
        cout << "Fail! " << outcome.error().Message() << "\n";
    }
    AlibabaCloud::OSS::ShutdownSdk(); // 释放
    return 0;
}
