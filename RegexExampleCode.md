## 금지어 조사 정규 표현식 코드 모음

### 이름
- 캐릭터 이름을 만들 때 특수문자를 사용 금지 단 예외는 있다.
    - (, ), [, ], _, -, {, } 는 허용.
- 그리고 이름이 'ㅎㅁ' 이라는 것도 허용하지 않는다(즉 완전한 한글이 아니면). 
- 한자도 허용하지 않는다.
  
```
#include "stdafx.h"
#include <regex>
#include <string>
#include <assert.h>

#define _W( __x )    L##__x

int _tmain(int argc, _TCHAR* argv[])
{
    std::wregex        regexCommandCapturePattern( _W("^(([가-힣]|[a-zA-Z0-9_]|[\\-\\[\\]\\(\\)\\{\\}])+)$") );
    std::wsmatch    regexMatchResult;

    {
        std::wstring    wstrInputString( _W("가나다abc-][(){}_AB194") );

        assert( true == std::regex_search( wstrInputString, regexMatchResult, regexCommandCapturePattern ) );
    }

    {
        std::wstring    wstrInputString( _W("ㅁ가나다abc-][(){}_AB194") );

        assert( false == std::regex_search( wstrInputString, regexMatchResult, regexCommandCapturePattern ) );
    }

    {
        std::wstring    wstrInputString( _W("★가나다abc-][(){}_AB194") );

        assert( false == std::regex_search( wstrInputString, regexMatchResult, regexCommandCapturePattern ) );
    }

    return 0;
}
```
  
<br>

출처: http://cafe.naver.com/ongameserver/6255
```
bool IsValidCharName(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	std::wregex     regexCommandCapturePattern( L"(([가-힣]|[a-zA-Z0-9_]|[\\-\\[\\]\\(\\)\\{\\}])+)");
	std::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}

assert(FALSE == Checker.IsValidCharName(L"★가나다abc-][(){}_AB194"));
assert(TRUE == Checker.IsValidCharName(L"가나다abc-][(){}_AB194"));
assert(FALSE == Checker.IsValidCharName(L"ㅁ가나다abc-][(){}_AB194"));
```


### 주민등록번호	
출처: http://cafe.naver.com/ongameserver/6255
```
bool IsValidResidentRegistrationNumber(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	std::wregex     regexCommandCapturePattern( L"\\d{6}\\-\\d{7}");
	std::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}

assert(FALSE == Checker.IsValidResidentRegistrationNumber(L"801234-798999"));
assert(TRUE == Checker.IsValidResidentRegistrationNumber(L"801234-7989990"));
assert(FALSE == Checker.IsValidResidentRegistrationNumber(L"801234-79899909"));
```
	

### url	
출처: http://cafe.naver.com/ongameserver/6255
```	
bool IsValidURL(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	std::wregex     regexCommandCapturePattern( L"(ftp|http|https):\\/\\/(\\w+)(\\.\\w+)*(\\/([\\w\\d])+\\/{0,1})*");
	std::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}

assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org/444/"));
assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org/444"));
assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org"));
assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver"));
assert(FALSE == Checker.IsValidURL(L"http://"));
assert(FALSE == Checker.IsValidURL(L"http://["));
```


### nic mac 주소
출처: http://cafe.naver.com/ongameserver/6255
```
bool IsValidMacAddress(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	tr1::wregex     regexCommandCapturePattern( L"([0-9a-fA-F][0-9a-fA-F]-){5}([0-9a-fA-F][0-9a-fA-F])");
	tr1::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}
```


### 이메일	
출처: http://cafe.naver.com/ongameserver/6255
```
bool IsValidEMail(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	std::wregex     regexCommandCapturePattern( L"[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*[.][a-zA-Z]{2,3}");
	std::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}

assert(FALSE == Checker.IsValidEMail(L"email"));
assert(FALSE == Checker.IsValidEMail(L"email@"));
assert(FALSE == Checker.IsValidEMail(L"email@daum"));
assert(FALSE == Checker.IsValidEMail(L"email@daum."));
assert(TRUE == Checker.IsValidEMail(L"a@daum.net"));
assert(TRUE == Checker.IsValidEMail(L"email-A@DAUM.Net"));
assert(FALSE == Checker.IsValidEMail(L"email-A@DAUM.Neta"));
assert(TRUE == Checker.IsValidEMail(L"email-A@DAUM.Ne"));
assert(FALSE == Checker.IsValidEMail(L"email-A@DAUM.N"));
assert(FALSE == Checker.IsValidEMail(L"email--A@DAUM.NET"));
```
	

### IPv4 주소	
출처: http://cafe.naver.com/ongameserver/6255
```
bool IsValidIPAddress(wchar_t* szStr )
{
	if (szStr == nullptr) {
		return false;
	}

	std::wregex     regexCommandCapturePattern( L"([1]?\\d{1,2}|[2][0-4]\\d|25[0-5])[.]([1]?\\d{1,2}|[2][0-4]\\d|25[0-5])[.]([1]?\\d{1,2}|[2][0-4]\\d|25[0-5])[.]([1]?\\d{1,2}|[2][0-4]\\d|25[0-5])");

	std::wsmatch    regexMatchResult;

	std::wstring    wstrInputString(szStr );

	return regex_match( wstrInputString, regexMatchResult, regexCommandCapturePattern );
}

assert(FALSE == Checker.IsValidIPAddress(L"333"));
assert(FALSE == Checker.IsValidIPAddress(L"333."));
assert(FALSE == Checker.IsValidIPAddress(L"333.333"));
assert(FALSE == Checker.IsValidIPAddress(L"333.333."));
assert(FALSE == Checker.IsValidIPAddress(L"333.333.333"));
assert(FALSE == Checker.IsValidIPAddress(L"333.333.333."));
assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333"));
assert(TRUE == Checker.IsValidIPAddress(L"133.133.133.133"));
assert(TRUE == Checker.IsValidIPAddress(L"255.255.255.255"));
assert(FALSE == Checker.IsValidIPAddress(L"255.255.255.256"));
assert(TRUE == Checker.IsValidIPAddress(L"56.255.255.255"));
assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333."));
assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333.333"));
```
