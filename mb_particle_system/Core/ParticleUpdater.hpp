#ifndef __MB_PS_PARTICLE_UPDATER__
#define __MB_PS_PARTICLE_UPDATER__

namespace mb
{
  namespace ps
  {
    class ParticleUpdater
    {
    public:
      virtual void configure( ParticlesInfoPtr particles ) = 0;
      virtual void update( const float&, ParticlesInfoPtr particles ) = 0;
    };
    typedef std::shared_ptr< ParticleUpdater > ParticleUpdaterPtr;
  }
}

#endif /* __MB_PS_PARTICLE_UPDATER__ */
