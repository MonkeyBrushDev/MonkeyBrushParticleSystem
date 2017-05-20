#ifndef __MB_PS_TIME_PARTICLE_UPDATER__
#define __MB_PS_TIME_PARTICLE_UPDATER__

#include "../Core/ParticleUpdater.hpp"

namespace mb
{
  namespace ps
  {
    class TimeParticleUpdater : public ParticleUpdater
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _times = particles->createAttributeArray<float>( ParticleAttrType::TIME );
      }
      virtual void update( const float& dt, ParticlesInfoPtr particles ) override
      {
        const unsigned int count = particles->getNumAliveParticles( );

        float* ts = _times->getData< float >( );

        for ( unsigned int i = 0; i < count; ++i )
        {
          ts[ i ] -= dt;
          if ( ts[ i ] <= 0.0f )
          {
            particles->kill( i );
          }
        }
      }
    protected:
      IParticleAttrArray* _times;
    };
  }
}

#endif /* __MB_PS_TIME_PARTICLE_UPDATER__ */
