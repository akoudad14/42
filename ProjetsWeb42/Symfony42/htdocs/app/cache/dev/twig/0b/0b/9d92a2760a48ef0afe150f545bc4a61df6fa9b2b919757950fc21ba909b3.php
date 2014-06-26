<?php

/* HackzillaTicketBundle:Ticket:show.html.twig */
class __TwigTemplate_0b0b9d92a2760a48ef0afe150f545bc4a61df6fa9b2b919757950fc21ba909b3 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("HackzillaTicketBundle::layout.html.twig");

        $this->blocks = array(
            'hackzilla_ticket_content' => array($this, 'block_hackzilla_ticket_content'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "HackzillaTicketBundle::layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 3
    public function block_hackzilla_ticket_content($context, array $blocks = array())
    {
        // line 4
        echo "<h1>";
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("HEADING_TICKET_ID", array("%id%" => $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "id"))), "html", null, true);
        echo "</h1>

<div class=\"row well\">
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 9
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_CREATED"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 10
        echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "createdAt"), "Y-m-d H:i:s"), "html", null, true);
        echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 15
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_CREATED_BY"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 16
        if ($this->env->getExtension('hackzilla_ticket_user_extension')->isTicketAdmin($this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "userCreatedObject"), "ROLE_TICKET_ADMIN")) {
            echo "<span class=\"label label-default\">";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_ADMIN"), "html", null, true);
            echo "</span> ";
        }
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "userCreatedObject"), "html", null, true);
        echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 21
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("HEADING_LAST_MESSAGE_BY"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 22
        if ($this->env->getExtension('hackzilla_ticket_user_extension')->isTicketAdmin($this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "lastUserObject"), "ROLE_TICKET_ADMIN")) {
            echo "<span class=\"label label-default\">";
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_ADMIN"), "html", null, true);
            echo "</span> ";
        }
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "lastUserObject"), "html", null, true);
        echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 27
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_STATUS"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 28
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "statusString")), "html", null, true);
        echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 33
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("HEADING_LAST_MODIFIED"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 34
        echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "lastMessage"), "Y-m-d H:i:s"), "html", null, true);
        echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 39
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_PRIORITY"), "html", null, true);
        echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
        // line 40
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "priorityString")), "html", null, true);
        echo "</div>
        </div>
    </div>
</div>

";
        // line 45
        $context["previousStatus"] = null;
        // line 46
        $context["previousPriority"] = null;
        // line 47
        echo "
<h3>";
        // line 48
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("HEADING_TICKET_THREAD"), "html", null, true);
        echo "</h3>
<div class=\"ticket-messages\">
";
        // line 50
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "messages"));
        foreach ($context['_seq'] as $context["_key"] => $context["message"]) {
            // line 51
            echo "<div class=\"ticket-message row well\">
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 54
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_AUTHOR"), "html", null, true);
            echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 55
            if ($this->env->getExtension('hackzilla_ticket_user_extension')->isTicketAdmin($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "userObject"), "ROLE_TICKET_ADMIN")) {
                echo "<span class=\"label label-default\">";
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_ADMIN"), "html", null, true);
                echo "</span> ";
            }
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "userObject"), "html", null, true);
            echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 60
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_DATE"), "html", null, true);
            echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 61
            echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "createdAt"), "Y-m-d H:i:s"), "html", null, true);
            echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 66
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_PRIORITY"), "html", null, true);
            echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 67
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priorityString")), "html", null, true);
            echo "</div>
        </div>
    </div>
    <div class=\"col-lg-6 col-md-6 col-sm-6\">
        <div class=\"row\">
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 72
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_STATUS"), "html", null, true);
            echo ":</div>
            <div class=\"col-lg-6 col-md-6 col-sm-6\">";
            // line 73
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "statusString")), "html", null, true);
            echo "</div>
        </div>
    </div>
    <div class=\"col-lg-12 col-md-12 col-sm-12\">
        &nbsp;
    </div>
    <div class=\"col-lg-12 col-md-12 col-sm-12\">
        ";
            // line 80
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("LABEL_MESSAGE"), "html", null, true);
            echo ":
        ";
            // line 81
            if ($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "message")) {
                // line 82
                echo "            <br>";
                echo nl2br(twig_escape_filter($this->env, $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "message"), "html", null, true));
                echo "
        ";
            } else {
                // line 84
                echo "            ";
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("MESSAGE_EMPTY"), "html", null, true);
                echo "
        ";
            }
            // line 86
            echo "    </div>
    ";
            // line 87
            if ((((!(isset($context["previousStatus"]) ? $context["previousStatus"] : $this->getContext($context, "previousStatus"))) || ((isset($context["previousStatus"]) ? $context["previousStatus"] : $this->getContext($context, "previousStatus")) != $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "status"))) || ((isset($context["previousPriority"]) ? $context["previousPriority"] : $this->getContext($context, "previousPriority")) != $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priority")))) {
                // line 88
                echo "    <div class=\"col-lg-12 col-md-12 col-sm-12\">
        &nbsp;
    </div>
    ";
            }
            // line 92
            echo "    <div class=\"col-lg-12 col-md-12 col-sm-12\">
        ";
            // line 93
            if ((!(isset($context["previousStatus"]) ? $context["previousStatus"] : $this->getContext($context, "previousStatus")))) {
                // line 94
                echo "            ";
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("MESSAGE_TICKET_OPENED", array("%priority%" => $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priorityString")))), "html", null, true);
                echo "
        ";
            } else {
                // line 96
                echo "            ";
                if (((isset($context["previousStatus"]) ? $context["previousStatus"] : $this->getContext($context, "previousStatus")) != $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "status"))) {
                    // line 97
                    echo "                ";
                    echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("MESSAGE_STATUS_CHANGED", array("%status%" => $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "statusString")))), "html", null, true);
                    echo "
            ";
                }
                // line 99
                echo "            ";
                if (((isset($context["previousPriority"]) ? $context["previousPriority"] : $this->getContext($context, "previousPriority")) != $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priority"))) {
                    // line 100
                    echo "                ";
                    echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("MESSAGE_PRIORITY_CHANGED", array("%priority%" => $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priorityString")))), "html", null, true);
                    echo "
            ";
                }
                // line 102
                echo "        ";
            }
            // line 103
            echo "    </div>
</div>
    ";
            // line 105
            $context["previousStatus"] = $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "status");
            // line 106
            echo "    ";
            $context["previousPriority"] = $this->getAttribute((isset($context["message"]) ? $context["message"] : $this->getContext($context, "message")), "priority");
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['message'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 108
        echo "</div>

";
        // line 110
        if (array_key_exists("form", $context)) {
            // line 111
            echo "<form action=\"";
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("hackzilla_ticket_reply", array("id" => $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "id"))), "html", null, true);
            echo "\" method=\"post\" ";
            echo $this->env->getExtension('form')->renderer->searchAndRenderBlock((isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")), 'enctype');
            echo ">

    ";
            // line 113
            $this->env->loadTemplate("HackzillaTicketBundle:Ticket:prototype.html.twig")->display(array_merge($context, array("form" => (isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")))));
            // line 114
            echo "
    ";
            // line 115
            echo $this->env->getExtension('form')->renderer->searchAndRenderBlock((isset($context["form"]) ? $context["form"] : $this->getContext($context, "form")), 'rest');
            echo "
    
    <p class=\"form_actions\">
        <button type=\"submit\" class=\"btn btn-primary\">";
            // line 118
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("BUTTON_UPDATE"), "html", null, true);
            echo "</button>
    </p>
</form>
";
        }
        // line 122
        echo "
<form action=\"";
        // line 123
        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("hackzilla_ticket_delete", array("id" => $this->getAttribute((isset($context["ticket"]) ? $context["ticket"] : $this->getContext($context, "ticket")), "id"))), "html", null, true);
        echo "\" method=\"post\">
    <input type=\"hidden\" name=\"_method\" value=\"DELETE\" />
    ";
        // line 125
        echo $this->env->getExtension('form')->renderer->searchAndRenderBlock((isset($context["delete_form"]) ? $context["delete_form"] : $this->getContext($context, "delete_form")), 'widget');
        echo "

    <a href=\"";
        // line 127
        echo $this->env->getExtension('routing')->getPath("hackzilla_ticket");
        echo "\" class=\"btn btn-default\">
        ";
        // line 128
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("BUTTON_BACK_TO_LIST"), "html", null, true);
        echo "
    </a>

    <button type=\"submit\" class=\"btn btn-danger\">";
        // line 131
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("BUTTON_DELETE"), "html", null, true);
        echo "</button>
</form>
";
    }

    public function getTemplateName()
    {
        return "HackzillaTicketBundle:Ticket:show.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 50,  195 => 54,  306 => 95,  303 => 94,  292 => 91,  287 => 77,  280 => 87,  178 => 80,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 93,  291 => 115,  286 => 113,  190 => 49,  321 => 128,  295 => 100,  274 => 53,  242 => 82,  236 => 42,  70 => 29,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 16,  313 => 84,  290 => 90,  276 => 110,  266 => 366,  263 => 105,  255 => 353,  245 => 83,  207 => 33,  194 => 52,  76 => 19,  200 => 31,  184 => 72,  58 => 32,  170 => 77,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 96,  325 => 94,  308 => 13,  304 => 122,  272 => 108,  267 => 78,  249 => 74,  216 => 86,  155 => 75,  146 => 34,  126 => 47,  124 => 46,  188 => 73,  181 => 81,  161 => 75,  320 => 84,  317 => 127,  311 => 83,  288 => 114,  284 => 76,  279 => 77,  275 => 86,  256 => 102,  250 => 100,  237 => 71,  232 => 94,  222 => 66,  191 => 26,  153 => 34,  150 => 34,  110 => 39,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 151,  282 => 161,  259 => 103,  244 => 43,  231 => 69,  226 => 131,  215 => 280,  186 => 51,  152 => 74,  114 => 40,  104 => 51,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 131,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 140,  281 => 75,  277 => 136,  271 => 374,  265 => 106,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 64,  228 => 41,  225 => 67,  213 => 69,  211 => 81,  197 => 30,  174 => 154,  148 => 69,  134 => 50,  127 => 29,  270 => 84,  253 => 78,  233 => 304,  212 => 60,  210 => 84,  206 => 57,  202 => 81,  198 => 80,  192 => 53,  185 => 61,  180 => 44,  175 => 41,  172 => 66,  167 => 76,  165 => 75,  160 => 60,  137 => 65,  113 => 55,  100 => 22,  90 => 28,  81 => 47,  65 => 22,  129 => 48,  97 => 52,  84 => 20,  34 => 26,  53 => 10,  77 => 23,  20 => 11,  23 => 4,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 125,  309 => 82,  305 => 115,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 111,  268 => 373,  264 => 74,  258 => 72,  252 => 68,  247 => 99,  241 => 97,  229 => 73,  220 => 65,  214 => 63,  177 => 43,  169 => 78,  140 => 66,  132 => 65,  128 => 60,  107 => 52,  61 => 36,  273 => 85,  269 => 133,  254 => 46,  243 => 66,  240 => 72,  238 => 96,  235 => 63,  230 => 93,  227 => 92,  224 => 39,  221 => 88,  219 => 87,  217 => 64,  208 => 124,  204 => 82,  179 => 84,  159 => 196,  143 => 54,  135 => 51,  119 => 27,  102 => 34,  71 => 24,  67 => 20,  63 => 13,  59 => 20,  38 => 5,  94 => 51,  89 => 28,  85 => 32,  75 => 43,  68 => 20,  56 => 16,  87 => 49,  21 => 11,  26 => 12,  93 => 47,  88 => 33,  78 => 25,  46 => 13,  27 => 4,  44 => 10,  31 => 4,  28 => 3,  201 => 56,  196 => 52,  183 => 50,  171 => 81,  166 => 38,  163 => 37,  158 => 74,  156 => 38,  151 => 70,  142 => 30,  138 => 51,  136 => 70,  121 => 61,  117 => 45,  105 => 55,  91 => 50,  62 => 17,  49 => 16,  24 => 18,  25 => 3,  19 => 1,  79 => 25,  72 => 18,  69 => 21,  47 => 15,  40 => 9,  37 => 6,  22 => 2,  246 => 67,  157 => 56,  145 => 53,  139 => 31,  131 => 61,  123 => 58,  120 => 57,  115 => 33,  111 => 40,  108 => 23,  101 => 37,  98 => 33,  96 => 48,  83 => 44,  74 => 39,  66 => 39,  55 => 31,  52 => 15,  50 => 11,  43 => 8,  41 => 7,  35 => 9,  32 => 4,  29 => 3,  209 => 58,  203 => 32,  199 => 265,  193 => 51,  189 => 52,  187 => 84,  182 => 85,  176 => 67,  173 => 46,  168 => 80,  164 => 61,  162 => 74,  154 => 71,  149 => 73,  147 => 55,  144 => 26,  141 => 70,  133 => 30,  130 => 57,  125 => 59,  122 => 45,  116 => 43,  112 => 32,  109 => 46,  106 => 30,  103 => 34,  99 => 30,  95 => 51,  92 => 21,  86 => 27,  82 => 33,  80 => 43,  73 => 22,  64 => 38,  60 => 16,  57 => 19,  54 => 34,  51 => 33,  48 => 7,  45 => 9,  42 => 29,  39 => 7,  36 => 7,  33 => 22,  30 => 21,);
    }
}
