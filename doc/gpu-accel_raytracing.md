# GPU-Accelerated Raytracing Renderer for Unity(Plugin)


real-time rendering framework / game engine 에서 씬 렌더링 데이터를 가져와 해당 씬을  GPGPU 혹은 GPU의 dedicated API 를 사용하여 raytracing 기법으로 렌더링을 하여 사실적인 결과를 보여줌. 이는 동영상으로 녹화되거나 real-time rendering 의 결과인 synthesized image 와 비교하여 reference image 로써 사용될 수 있음.

- 유사 사례 : [Octane Renderer at Unity(Youtube)](https://www.youtube.com/watch?v=k0U_-9Mjuxw&feature=youtu.be&t=120)

사실 상 octane renderer 의 기본적인 기술을 따라 구현할 예정임.

# 개략적인 구조도

![](./raytracing_one_page_proposal.png)

# 데모

![](./raytracing_thenexetweek.png)