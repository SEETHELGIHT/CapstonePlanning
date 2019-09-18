# GPU-Accelerated Raytracing Renderer for Unity(Plugin)

real-time rendering framework / game engine 에서 씬 렌더링 데이터를 가져와 해당 씬을  GPGPU(CUDA/OpenCL) 혹은 GPU의 driver API(DirectX/HLSL) 를 사용하여 raytracing 기법으로 렌더링을 하여 photorealistic image 를 만듦. real-time rendering 의 결과인 synthesized image 와 비교하여 reference image 로써 사용되거나, 연속적으로 이미지를 생성하여 video 로 결과를 만들어 낼 수 있음.

- 유사 사례 : [Octane Renderer at Unity(Youtube)](https://www.youtube.com/watch?v=k0U_-9Mjuxw&feature=youtu.be&t=120)

# 개략적인 구조도

![](./raytracing_one_page_proposal.png)

# 데모

![](./raytracing_thenexetweek.png)

# Require Techiniques

기술은 Octane Render 의 방법을 모방.(CUDA, Metropolis Light Transport)

  - Raytracing 
      - pixel 별 ray 의 처리를 고안해야함. 단순히 recursive 하게 갈것인지, 첫번째 surface 의 표면의 path-tracing 을 할것인지
      - 각종 통계적 기법에 대한 학습 및 이에 대한 구현에 대해서 알아야함. (MCMC, metrpolis light transport)
      - acceleration structure : BVH
  - CUDA(GPGPU-Optimization)
      - 기본적인 programming interface 에 대한 구조는 파악했으나 global memory fetch 가 잦은 프로그램의 성능을 향상시킬 방법을 찾아야함.
        - traversal optimization
      - cuda stream, graph 학습

  - Unity : rendering data-transfer 에 대한 구체적인 방법이 필요함. 현재는(190918) 아래 그림의 형태로 데이터를 가져올 예정.
      - 프로세스를 분리할 것인가? 자식 형태로 구성할 것인가?