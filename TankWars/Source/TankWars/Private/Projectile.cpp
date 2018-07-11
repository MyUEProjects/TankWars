// No Specific Copyright

//Includes
#include "Projectile.h"


// Constructor
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Set Components
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchBlast"));

	//Set Component Properties
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	SetRootComponent(CollisionMesh);
	LaunchBlast->AttachTo(RootComponent);
	ProjectileMovement->bAutoActivate = false;

}

//Used to launch the projectile
void AProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}

