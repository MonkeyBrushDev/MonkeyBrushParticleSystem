#ifndef __MB_PS_TIME_PARTICLE_GENERATOR__
#define __MB_PS_TIME_PARTICLE_GENERATOR__

#include "../Core/ParticleGenerator.hpp"

namespace mb
{
  namespace ps
  {
    class TimeParticleGenerator : public ParticleGenerator
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _times = particles->createAttributeArray< float >( ParticleAttrType::TIME );
      }
      virtual void generate( const float&, ParticlesInfoPtr particles,
        unsigned int start, unsigned int end ) override
      {
        float* ts = _times->getData< float >( );
        for ( unsigned int i = start; i < end; ++i )
        {
          float t = RandomFloat( 0.1f, 2.0f );
          ts[ i ] = t;
        }
      }
    protected:
      float RandomFloat( float min, float max )
      {
        float r = ( float ) rand( ) / ( float ) RAND_MAX;
        return min + r * ( max - min );
      }
      IParticleAttrArray* _times;
    };
  }
}

#endif /* __MB_PS_TIME_PARTICLE_GENERATOR__ */
