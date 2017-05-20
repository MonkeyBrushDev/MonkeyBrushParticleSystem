#ifndef __MB_PS_PARTICLE_RENDERER__
#define __MB_PS_PARTICLE_RENDERER__

#include "ParticleInfo.hpp"

namespace mb
{
  namespace ps
  {
    class ParticleRenderer
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) = 0;
      virtual void update( const float&, ParticlesInfoPtr particles ) = 0;
    };
    typedef std::shared_ptr< ParticleRenderer > ParticleRendererPtr;
  }
}

#endif /* __MB_PS_PARTICLE_RENDERER__ */
