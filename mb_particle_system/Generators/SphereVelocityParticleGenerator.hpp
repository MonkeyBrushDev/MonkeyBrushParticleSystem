#ifndef __MB_PS_SPHERE_VELOCITY_PARTICLE_GENERATOR__
#define __MB_PS_SPHERE_VELOCITY_PARTICLE_GENERATOR__

#include "../Core/ParticleGenerator.hpp"

namespace mb
{
  namespace ps
  {
    class SphereVelocityParticleGenerator : public ParticleGenerator
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _velocities = particles->createAttributeArray< Vector3 >( ParticleAttrType::VELOCITY );

        _magnitude = Vector3( 1.0f );
      }
      virtual void generate( const float&, ParticlesInfoPtr particles,
        unsigned int start, unsigned int end ) override
      {
        auto vs = _velocities->getData< Vector3 >( );

        const auto posMin = Vector3( -1.0f );
        const auto posMax = Vector3( 1.0f );

        for ( unsigned int i = start; i < end; ++i )
        {
          auto x = RandomFloat( posMin.x( ), posMax.x( ) );
          auto y = RandomFloat( posMin.y( ), posMax.y( ) );
          auto z = RandomFloat( posMin.z( ), posMax.z( ) );
          vs[ i ] = Vector3( x, y, z ).getNormalized( ) * _magnitude;
        }
      }
    protected:
      float RandomFloat( float min, float max )
      {
        float r = ( float ) rand( ) / ( float ) RAND_MAX;
        return min + r * ( max - min );
      }
      Vector3 _magnitude;
      IParticleAttrArray* _velocities;
    };
  }
}

#endif /* __MB_PS_SPHERE_VELOCITY_PARTICLE_GENERATOR__ */
