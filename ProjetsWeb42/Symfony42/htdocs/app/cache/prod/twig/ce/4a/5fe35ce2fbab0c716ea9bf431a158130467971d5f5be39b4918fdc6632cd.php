<?php

/* CCDNForumForumBundle:User/Post/Partial:item_post_head.html.twig */
class __TwigTemplate_ce4a5fe35ce2fbab0c716ea9bf431a158130467971d5f5be39b4918fdc6632cd extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        ob_start();
        // line 3
        echo "<div class=\"row clearfix\">
\t    <div class=\"col-md-7\">
\t\t\t<h3 class=\"panel-title\">";
        // line 6
        if ($this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getCreatedBy")) {
            // line 7
            echo $this->env->getExtension('translator')->trans("post.posted-by", array(), "CCDNForumForumBundle");
            // line 8
            echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getCreatedBy"), "username"), "html", null, true);
            // line 10
            echo "&nbsp;&#183;&nbsp;";
        }
        // line 14
        echo "<span class=\"timestamper\" title=\"";
        echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getCreatedDate"), "Y-m-d H:i:s T Z", "Europe/London"), "html", null, true);
        echo "\">";
        // line 15
        echo twig_escape_filter($this->env, twig_date_format_filter($this->env, $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getCreatedDate"), $this->getAttribute($this->getAttribute((isset($context["ccdn_forum_forum"]) ? $context["ccdn_forum_forum"] : null), "item_post"), "created_datetime_format")), "html", null, true);
        // line 16
        echo "</span>
\t\t\t</h3>
\t    </div>

\t    <div class=\"col-md-5 pull-right text-right\">
\t        ";
        // line 21
        if (($this->getAttribute((isset($context["post"]) ? $context["post"] : null), "id") && (!$this->getAttribute((isset($context["post"]) ? $context["post"] : null), "isDeleted")))) {
            // line 22
            echo "\t            <div class=\"btn-group\">
\t                <a class=\"btn btn-xs btn-icon-only\" title=\"show post\"
\t\t\t\t\t href=\"";
            // line 24
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_post_show", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
            echo "\">
\t\t\t\t\t\t<i class=\"glyphicon glyphicon-fullscreen\"></i>
\t\t\t\t\t</a>
\t                <a class=\"btn btn-xs btn-icon-only\" href=\"#post_";
            // line 27
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"), "html", null, true);
            echo "\">
\t\t\t\t\t\t<i class=\"glyphicon glyphicon-link\"></i>
\t\t\t\t\t</a>
\t            </div>
\t        ";
        }
        // line 33
        if ((($this->env->getExtension('security')->isGranted("ROLE_USER") && $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "id")) && ($this->env->getExtension('security')->isGranted("ROLE_MODERATOR") || (!$this->getAttribute((isset($context["post"]) ? $context["post"] : null), "isDeleted"))))) {
            // line 34
            echo "&nbsp;
                <div class=\"dropdown btn-group text-left\">
                    <a class=\"dropdown-toggle btn btn-xs btn-icon-only\" data-toggle=\"dropdown\" href=\"#\">
\t\t\t\t\t\t<i class=\"glyphicon glyphicon-cog\"></i>
\t\t\t\t\t\t<span class=\"caret\"></span>
\t\t\t\t\t</a>
                    <ul class=\"dropdown-menu pull-right content-left\" style=\"z-index:15;\">";
            // line 42
            if ($this->env->getExtension('authorizer')->canReplyToTopic($this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getTopic"))) {
                // line 43
                echo "<li>
\t\t\t\t\t\t\t\t<a rel=\"nofollow\"
\t\t\t\t\t\t\t\t href=\"";
                // line 45
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_topic_reply", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "topicId" => $this->getAttribute($this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getTopic"), "getId"))), "html", null, true);
                echo "\">
\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-pencil\"></i>";
                // line 47
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.topic.reply", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 48
                echo "</a>
\t\t\t\t\t\t\t</li>";
            }
            // line 52
            if ($this->env->getExtension('authorizer')->canEditPost((isset($context["post"]) ? $context["post"] : null))) {
                // line 53
                echo "<li>
\t\t\t\t\t\t\t\t<a rel=\"nofollow\" id=\"post_edit[";
                // line 54
                echo twig_escape_filter($this->env, twig_slice($this->env, $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getBody"), 0, 24), "html", null, true);
                echo "]\"
\t\t\t\t\t\t\t\t href=\"";
                // line 55
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_post_edit", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
                echo "\">
\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-pencil\"></i>";
                // line 57
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.edit", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 58
                echo "</a>
\t\t\t\t\t\t\t</li>";
            }
            // line 62
            if ($this->env->getExtension('authorizer')->canDeletePost((isset($context["post"]) ? $context["post"] : null))) {
                // line 63
                echo "<li>
\t\t\t\t\t\t\t\t<a rel=\"nofollow\"
\t\t\t\t\t\t\t\t href=\"";
                // line 65
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_post_delete", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
                echo "\">
\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-trash\"></i>";
                // line 67
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.post.delete", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 68
                echo "</a>
\t\t\t\t\t\t\t</li>";
            }
            // line 72
            if ($this->env->getExtension('authorizer')->canRestorePost((isset($context["post"]) ? $context["post"] : null))) {
                // line 73
                echo "<li>
                                <a rel=\"nofollow\" href=\"";
                // line 74
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_moderator_post_restore", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
                echo "\">
                                    <i class=\"glyphicon glyphicon-trash\"></i>";
                // line 76
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.post.restore", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 77
                echo "</a>
                            </li>";
            }
            // line 81
            if ($this->env->getExtension('authorizer')->canLockPost((isset($context["post"]) ? $context["post"] : null))) {
                // line 82
                echo "<li>
                                <a rel=\"nofollow\" href=\"";
                // line 83
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_moderator_post_lock", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
                echo "\">
                                    <i class=\"glyphicon glyphicon-lock\"></i>";
                // line 85
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.post.lock", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 86
                echo "</a>
                            </li>";
            }
            // line 90
            if ($this->env->getExtension('authorizer')->canUnlockPost((isset($context["post"]) ? $context["post"] : null))) {
                // line 91
                echo "<li>
                                <a rel=\"nofollow\" href=\"";
                // line 92
                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_moderator_post_unlock", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "postId" => $this->getAttribute((isset($context["post"]) ? $context["post"] : null), "getId"))), "html", null, true);
                echo "\">
                                    <i class=\"glyphicon glyphicon-lock\"></i>";
                // line 94
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.post.unlock", array(), "CCDNForumForumBundle"), "html", null, true);
                // line 95
                echo "</a>
                            </li>";
            }
            // line 99
            echo "</ul>
                </div>";
        }
        // line 102
        echo "</div>
\t</div>";
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    public function getTemplateName()
    {
        return "CCDNForumForumBundle:User/Post/Partial:item_post_head.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  205 => 79,  234 => 94,  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 104,  195 => 84,  306 => 95,  303 => 123,  292 => 119,  287 => 77,  280 => 87,  178 => 73,  12 => 36,  118 => 65,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 122,  291 => 115,  286 => 115,  190 => 72,  321 => 128,  295 => 100,  274 => 111,  242 => 82,  236 => 92,  70 => 37,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 132,  313 => 84,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 80,  194 => 52,  76 => 10,  200 => 75,  184 => 75,  157 => 81,  83 => 45,  58 => 30,  170 => 85,  139 => 77,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 135,  325 => 94,  308 => 126,  304 => 122,  272 => 108,  267 => 105,  249 => 74,  216 => 86,  155 => 63,  146 => 10,  126 => 47,  124 => 68,  188 => 70,  181 => 81,  161 => 27,  320 => 84,  317 => 127,  311 => 128,  288 => 114,  284 => 114,  279 => 77,  275 => 86,  256 => 103,  250 => 99,  237 => 92,  232 => 91,  222 => 85,  191 => 81,  153 => 78,  150 => 34,  145 => 82,  110 => 46,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 131,  215 => 280,  186 => 69,  152 => 85,  114 => 63,  104 => 53,  96 => 49,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 131,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 117,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 93,  228 => 88,  225 => 86,  213 => 82,  211 => 83,  197 => 74,  174 => 65,  148 => 83,  134 => 50,  127 => 62,  270 => 84,  253 => 78,  233 => 304,  212 => 60,  210 => 81,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 76,  180 => 44,  175 => 89,  172 => 70,  167 => 94,  165 => 69,  160 => 91,  137 => 76,  120 => 61,  113 => 56,  100 => 52,  90 => 47,  81 => 13,  65 => 33,  129 => 63,  97 => 27,  84 => 39,  34 => 14,  53 => 24,  37 => 14,  52 => 27,  77 => 42,  74 => 9,  20 => 11,  23 => 4,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 125,  309 => 82,  305 => 124,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 111,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 96,  229 => 73,  220 => 84,  214 => 63,  177 => 102,  169 => 95,  140 => 62,  132 => 66,  128 => 72,  111 => 53,  107 => 57,  61 => 21,  273 => 85,  269 => 109,  254 => 102,  246 => 67,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 89,  227 => 92,  224 => 39,  221 => 88,  219 => 87,  217 => 83,  208 => 124,  204 => 82,  179 => 67,  159 => 196,  143 => 81,  135 => 67,  131 => 65,  119 => 57,  108 => 58,  102 => 55,  71 => 36,  67 => 33,  63 => 29,  59 => 27,  47 => 21,  38 => 15,  94 => 48,  89 => 48,  85 => 16,  79 => 43,  75 => 39,  68 => 32,  56 => 28,  50 => 23,  29 => 8,  87 => 47,  72 => 38,  55 => 3,  21 => 3,  26 => 4,  98 => 54,  93 => 52,  88 => 46,  78 => 11,  46 => 12,  27 => 7,  40 => 16,  44 => 11,  35 => 6,  31 => 10,  43 => 14,  41 => 33,  28 => 29,  201 => 56,  196 => 52,  183 => 68,  171 => 81,  166 => 30,  163 => 92,  158 => 90,  156 => 76,  151 => 77,  142 => 30,  138 => 61,  136 => 72,  123 => 50,  121 => 58,  117 => 46,  115 => 59,  105 => 56,  101 => 53,  91 => 25,  69 => 34,  66 => 38,  62 => 32,  49 => 22,  24 => 4,  32 => 5,  25 => 6,  22 => 2,  19 => 1,  209 => 82,  203 => 86,  199 => 85,  193 => 51,  189 => 52,  187 => 77,  182 => 74,  176 => 72,  173 => 99,  168 => 84,  164 => 61,  162 => 74,  154 => 86,  149 => 61,  147 => 60,  144 => 26,  141 => 7,  133 => 74,  130 => 73,  125 => 61,  122 => 67,  116 => 64,  112 => 62,  109 => 52,  106 => 57,  103 => 55,  99 => 49,  95 => 53,  92 => 44,  86 => 44,  82 => 41,  80 => 40,  73 => 28,  64 => 28,  60 => 21,  57 => 23,  54 => 27,  51 => 16,  48 => 22,  45 => 36,  42 => 16,  39 => 32,  36 => 12,  33 => 12,  30 => 5,);
    }
}
