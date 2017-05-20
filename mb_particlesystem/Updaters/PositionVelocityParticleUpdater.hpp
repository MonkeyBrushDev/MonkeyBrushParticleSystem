#ifndef __MB_PS_POSITION_VELOCITY_PARTICLE_UPDATER__
#define __MB_PS_POSITION_VELOCITY_PARTICLE_UPDATER__

#include "../Core/ParticleUpdater.hpp"

namespace mb
{
  namespace ps
  {
    class PositionVelocityParticleUpdater : public ParticleUpdater
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) override
      {
        _positions = particles->createAttributeArray< Vector3 >( ParticleAttrType::POSITION );
        _velocities = particles->createAttributeArray< Vector3 >( ParticleAttrType::VELOCITY );
      }
      virtual void update( const float& dt, ParticlesInfoPtr particles ) override
      {
        const unsigned int count = particles->getNumAliveParticles( );

        auto ps = _positions->getData< Vector3 >( );
        auto vs = _velocities->getData< Vector3 >( );

        for ( unsigned int i = 0; i < count; ++i )
        {
          Vector3 v = vs[ i ] * dt;
          ps[ i ] += v;
        }
      }
    protected:
      IParticleAttrArray* _positions;
      IParticleAttrArray* _velocities;
    };
  }
}

#endif /* __MB_PS_POSITION_VELOCITY_PARTICLE_UPDATER__ */
