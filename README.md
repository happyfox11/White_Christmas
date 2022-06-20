# 🎄 White_Christmas
Using opengl, three-dimensional expression of the scenery on a snowy day !  
<br/>

## 🎅 개발환경  
 - Programming Language: C++
 - API(Software Interface) : OpenGL
 - IDE : Visual Studio 2019
 - Hardware 환경 : Windows 10 64bit OS, RAM 8GB , quad core  
<br/>

## ❄️ 개요
- Opengl을 이용한, 눈이 오는 크리스마스의 풍경을 동적으로 표현  
- 2차원 및 기본적인 3차원 그래픽스 모델에 기하변환(신축/ 이동/ 회전) 적용  
  - 모델좌표계, 전역좌표계, 시점좌표계 등의 좌표계 개념을 이해  
- 2차원 및 기본적인 3차원 그래픽스 모델을 신축/ 이동/ 회전시켜서, 새로운 물체 형성  
- Menu, KeyBoard, Reshape 콜백을 이용  
	- 키보드 콜백을 통해 카메라의 시점을 달리함으로써, 모든 풍경(좌표)을 확인 가능  
	- 메뉴 콜백을 통해, 사용자가 요구하는 특정한 기능을 제공  
- 생성한 물체들에 조명(주변광과 분산광)을 비추고 그 위치를 조절함으로써, 현실감을 부여   
- 뷰잉 변환과 투영 변환을 거쳐서, 3차원 그래픽스 장면을 2차원 화면에 출력  
- 가시성 여부를 판단한 후, 은면제거를 통해 렌더링 처리 시간을 단축   
<br/>

## 🎁 주요 클래스
<img width="90%" src="https://user-images.githubusercontent.com/89199587/174460738-47c4b0c6-96d8-474c-9ff9-9d79219af39f.png"/>  
<br/>

## ⛄ 주요 기능 설명  
### 1. Reshape Callback :  
윈도우의 크기를 조절함에 따라, 크기를 적절하게 변경가능  
<img width="90%" src="https://user-images.githubusercontent.com/89199587/174573060-b60cec6e-ef06-4af5-8caf-3ef4919fdbb3.png"/>  
### 2. Keyboard Callback :  
키보드의 방향키를 이용하여 카메라의 시점을 달리함으로써, 화면 내의 모든 좌표를 상하좌우로 회전하며 확인 가능  
<img width="90%" src="https://user-images.githubusercontent.com/89199587/174573079-f5aadd1f-39c6-4aa6-8109-c2f15f4657ad.png"/>  
### 3. Menu Callback :  
시간(밤/ 낮) 지정하고, 장소(야외/ 실내) 지정가능하며, 크리스마스 트리의 크기를 선택하여 지정 가능  
<img width="90%" src="https://user-images.githubusercontent.com/89199587/174573114-9c4eac6d-7cc6-4597-a443-888fc5b6d203.png"/>  
<br/>  

## 📑 참고문헌    
<img width="40%" src="https://user-images.githubusercontent.com/89199587/174460749-6c5cda16-9155-4da3-b17a-f33a005187c2.png"/>  
[https://cs.lmu.edu/~ray/notes/openglexamples/ : Bouncing Balls ]
