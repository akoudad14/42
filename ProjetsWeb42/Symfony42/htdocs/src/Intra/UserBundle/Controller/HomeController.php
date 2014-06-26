<?php

namespace Intra\UserBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class HomeController extends Controller
{
	public function homeAction()
	{
        return $this->render('IntraUserBundle:UserAdmin:home.html.twig');
	}
}