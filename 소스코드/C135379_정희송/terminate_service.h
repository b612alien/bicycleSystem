// terminate_service.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class TerminateServiceUI;

// 로그아웃하는 SignOut control class를 정의
class TerminateService {
public:
    TerminateService(); // 계정 목록을 초기화하는 생성자
    void GetInterface(TerminateServiceUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
};