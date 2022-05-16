# cowcastleminiproject1

+ ### mini project 주제
  출퇴근을 관리하는 시스템

+ ### mini project 에 대한 소개
  mini project - "**SRC checker**"는 출근시간과 퇴근시간을 관리하기 위해 구현된 시스템이다.(SRC는 super rapid commute의 축약임)

![meeting-594091_1920](https://user-images.githubusercontent.com/104507267/166092647-9c2ef149-9aa5-4fab-b361-8e2dba1ce23a.jpg)

+ ### mini project 가 가지고 있는 대략적인 기능 설명
  + 사람 정보를 **추가**하는 함수 [Link](https://github.com/Losecow/cowcastle.github.io/blob/main/functions/addPrivacy.md)
  + 사람 정보를 **삭제**하는 함수 [Link](https://github.com/Losecow/cowcastle.github.io/blob/main/functions/deletePrivacy.md)
  + 사람 정보를 **수정**하는 함수 [Link](https://github.com/Losecow/cowcastle.github.io/blob/main/functions/updatePrivacy.md)
  + 사람 정보를 **조회**하는 함수 [Link](https://github.com/Losecow/cowcastle.github.io/blob/main/functions/readPrivacy.md)
  + 사람 정보를 파일에 **저장**하는 함수 [Link](사람-정보-파일에-저장)  
    i) 사람의 정보를 파일에 저장
  + 저장한 **파일을 불러오는** 함수 [Link](저장한-파일-불러오기)  
    i) 사람의 개인 정보를 불러오는 함수  
    ii) 출퇴근 기록을 불러오는 함수  
  + 출퇴근 **인증** [Link](출퇴근-인증)  
    i) 출근 시간을 인증하고 기록하는 함수  
    ii) 퇴근 시간을 인증하고 기록하는 함수  
  + 출퇴근 **log 확인** [Link](출퇴근-log-확인)  
    i) 출근과 퇴근 기록을 불러오는 함수 
  + **지각**한 사람 체크 [Link](지각한-사람-체크)  
    i) 지각한 사람만 모아 체크하는 함수  
  
+ ### 개발환경 및 언어
  +Linux, Github, MarkDown 언어, C 언어, Git 

+ ### 팀소개 및 팀원이 맡은 역할
  + 팀원 빈지성 : 깃헙 관리, 프로그램 코드 개발, 출퇴근 관련 정보 수집
  + 팀원 박진우 : UI 디자인, 프로그램 코드 개발, 출퇴근 관련 정보 수집

+ ### 각자 구현한 함수
|함수 이름|개발자|개발 과정 확인|
|---------|---|:--:|
|selectMenu 메뉴 함수|박진우 |개발완료|
|CRUD 함수 구현|빈지성|개발완료|
|saveData 데이터 저장 함수|박진우|개발완료|
|loadData 데이터 불러오는 함수|박진우|개발완료|
|checkCommute 출퇴근 확인 함수|빈지성|개발완료|
|expressWrong 출퇴근 중복 체크 함수|빈지성|개발완료|
|checkLate 지각자 체크 함수|빈지성|개발완료|
|checkMasterKey 마스터키 체크 함수|빈지성|개발완료|
|readCommute 출퇴근 정보 읽어오는 함수|박진우|개발완료|
|read_Onecommute 하나의 출퇴근 정보만 불러오는 함수|박진우|개발완료|
|findPrivacy 이름/직책으로 검색이 가능한 함수|박진우|개발완료|

+ ### 개발일정
|일시|개발자|개발 내용|
|---------|---|:--:|
|4/26-5/2(9주차)|빈지성, 박진우|주제 선정,구조체,함수 선언,README.md 작성|
|5/3-5/9(10주차)|빈지성,박진우|crud 구현,menu 구현|
|5/10-5/16(11주차)|빈지성|checkCommute,expressWrong,checkLate,checkMasterKey 함수 구현|
|5/10-5/16(11주차)|박진우|saveData,loadData,readCommute,read_Onecommute,findPrivacy 함수 구현|


+ ### 팀원 협업 평가
 + 팀원 빈지성
 + 팀원 박진우
