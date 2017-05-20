#ifndef __MB_PS_ACCELERATION_PARTICLE_GENERATOR__
#define __MB_PS_ACCELERATION_PARTICLE_GENERATOR__

#include "../Core/ParticleGenerator.hpp"

namespace mb
{
  namespace ps
  {
    class AccelerationParticleGenerator : public ParticleGenerator
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _accelerations = particles->createAttributeArray< Vector3 >( ParticleAttrType::ACCELERATION );

        _minAcceleration = Vector3( 0.0f );
        _maxAcceleration = Vector3( 1.0f );
      }
      virtual void generate( const float&, ParticlesInfoPtr particles,
        unsigned int start, unsigned int end ) override
      {
        auto as = _accelerations->getData< Vector3 >( );

        for ( unsigned int i = start; i < end; ++i ) {
          as[ i ][ 0 ] = RandomFloat( _minAcceleration.x( ), _maxAcceleration.x( ) );
          as[ i ][ 1 ] = RandomFloat( _minAcceleration.y( ), _maxAcceleration.y( ) );
          as[ i ][ 2 ] = RandomFloat( _minAcceleration.z( ), _maxAcceleration.z( ) );
        }
      }
    protected:
      float RandomFloat( float min, float max )
      {
        float r = ( float ) rand( ) / ( float ) RAND_MAX;
        return min + r * ( max - min );
      }
      Vector3 _minAcceleration;
      Vector3 _maxAcceleration;
      IParticleAttrArray* _accelerations;
    };
  }
}

#endif /* __MB_PS_ACCELERATION_PARTICLE_GENERATOR__ */
