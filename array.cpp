#include "Array.h"
#include <cstdlib>
#include<iostream>
using namespace std;
Array::Array(int size)
{
	//사이즈를 확인하고 양수이면 new를 사용하여 배열 data를 할당, len값 초기화
	if(size<=0) //size<0 으로 설정하면 size가 0과 양수를 포함하므로 size<=0으로 조건문을 수정한다.
	{
		cout<<"Please Input positive number. ERROR!"; // 양수가 아닌 값일 경우 오류 출력
		cout<<endl; // = printf("\n");
	}
	else // 양수가 제대로 입력 되었을 경우
	{
		data=new int[size]; // new를 사용하여서 크기를 size만큼으로  동적 메모리 할당
		len=size; // len의 값을 size로 초기화
	}
}
Array::~Array()
{
	// 소멸자; 할당된 메모리 해제
	// 할당된 메모리는 delete를 통해서 해제한다.
	delete data;

}
int Array::length() const
{
	// 배열의 크기 리턴
	// 위에서 len의 값을 size로 초기화했으므로 배열의 크기는 len을 리턴하면 된다.
	return len;
}

// 배열에 원소를 대입하거나 값을 반환하는 부분으로 []연산자의 오버로딩이다
int& Array::operator[](int i) // 배열에 원소 삽입
{
	static int tmp;

	// 배열의 인덱스가 범위 내에 있으면 값 리턴, 그렇지 않으면 에러메세지 출력하고 tmp리턴
	if(i >= 0 && i < len) // 배열의 인덱스가 범위 내에 있을 경우
	{
		return data[i];
	}
	else // 배열의 인덱스가 범위 내에 없을 경우
	{
		cout<<"Array bound error!"<<endl; // 문제의 형식에 맞게 Error 출력
		return tmp;
	}
}

int Array::operator[](int i) const // 배열의 원소값 반환
{
	//배열의 인덱스가 범위 내에 있으면 값을 리턴, 그렇지 않으면 에러메세지 출력하고 0을 리턴
	if(i >= 0 && i<len) // 범위 내에 있을 경우
	{
		return data[i]; // data의 i번째 인덱스의 값 리턴
	}
	else // 범위 내에 없을 경우
	{
		cout<<"Array bound error!"<<endl; // 형식에 맞게 Error 출력
		return 0;
	}
}
void Array::print() //배열의 모든 내용을 출력해주는 함수
{
	int i; // 반복문을 위한 변수 설정
	cout<<"[";
	for(i=0; i<len; i++) // 모든 내용을 출력하기 위해서 반복문을 수행
	{
		if(i==0) cout<<data[i];
		else cout<<" "<<data[i]; //형식에 맞게 값을 출력함
	}
	
	cout<<"]";	
	cout<<endl;
}
