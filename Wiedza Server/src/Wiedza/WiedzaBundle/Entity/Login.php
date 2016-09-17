<?php
/**
 * User: gabrielkras
 * Date: 21/08/16
 * Time: 18:58
 */

namespace Wiedza\WiedzaBundle\Entity;

use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Security\Core\Role\Role;
use Symfony\Component\Security\Core\User\AdvancedUserInterface;

/**
 * Class User -> This class represents a user system
 * @package Wiedza\WiedzaBundle\Entity
 *
 * @ORM\Table(name="wiedza_login")
 * @ORM\Entity(repositoryClass="Wiedza\WiedzaBundle\Repository\LoginRepository")
 */
class Login implements AdvancedUserInterface
{
    const ENABLED   = 1;
    const DISABLED  = 0;

    /**
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id()
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\Column(name="email", type="string", length=255)
     */
    private $email;

    /**
     * @ORM\Column(name="password", type="string", length=128)
     */
    private $password;

    /**
     * @ORM\Column(name="salt", type="string", length=64)
     */
    private $salt;

    /**
     * @ORM\Column(name="rfid", type="string", length=255, nullable=true)
     */
    private $rfid;

    /**
     * @ORM\ManyToMany(targetEntity="Wiedza\WiedzaBundle\Entity\Roles", inversedBy="login")
     */
    private $roles;

    /**
     * @ORM\Column(name="enabled", type="integer")
     */
    private $enabled;

    /**
     * @ORM\Column(name="created", type="datetime")
     */
    private $created;

    /**
     * @ORM\Column(name="updated", type="datetime")
     */
    private $updated;


    /**
     * Login constructor.
     * @param $email
     * @param $password
     * @param $rfid
     */
    public function __construct($email, $password, $rfid = null)
    {
        $this->email = $email;
        $this->password = $password;
        $this->rfid = $rfid;
        $this->enabled = self::ENABLED;
        $this->roles = new ArrayCollection();
    }

    /**
     * @return mixed
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return mixed
     */
    public function getRfid()
    {
        return $this->rfid;
    }

    /**
     * @param Roles $role
     */
    public function addRole(Roles $role)
    {
        $this->roles->add($role);

    }

    /**
     * @param Roles $role
     */
    public function removeRole(Roles $role)
    {
        $this->roles->remove($role);
    }

    public function isAccountNonExpired()
    {
        // TODO: Implement isAccountNonExpired() method.
    }

    public function isAccountNonLocked()
    {
        // TODO: Implement isAccountNonLocked() method.
    }

    public function isCredentialsNonExpired()
    {
        // TODO: Implement isCredentialsNonExpired() method.
    }

    /**
     * @return int
     */
    public function isEnabled()
    {
        return $this->enabled;
    }

    public function getRoles()
    {
        return $this->roles;
    }

    public function getPassword()
    {
        return $this->salt;
    }

    public function getSalt()
    {
        return $this->password;
    }

    public function getUsername()
    {
        return $this->email;
    }

    public function eraseCredentials()
    {
        // TODO: Implement eraseCredentials() method.
    }

}