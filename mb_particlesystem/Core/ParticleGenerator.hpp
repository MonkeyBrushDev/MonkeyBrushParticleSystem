#ifndef __MB_PS_PARTICLE_GENERATOR__
#define __MB_PS_PARTICLE_GENERATOR__

#include "ParticleInfo.hpp"

namespace mb
{
  namespace ps
  {
    class ParticleGenerator
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) = 0;
      virtual void generate( const float&, ParticlesInfoPtr particles,
        unsigned int start, unsigned int end ) = 0;
    };
    typedef std::shared_ptr< ParticleGenerator > ParticleGeneratorPtr;
  }
}

#endif /* __MB_PS_PARTICLE_GENERATOR__ */
