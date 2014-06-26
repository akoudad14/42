<?php

/* SonataAdminBundle:Core:add_block.html.twig */
class __TwigTemplate_f7ed4c7227de333537fcaec857d6a8728a725d2102177ab91c412cfdd5b54fb5 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'user_block' => array($this, 'block_user_block'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        $this->displayBlock('user_block', $context, $blocks);
    }

    public function block_user_block($context, array $blocks = array())
    {
        // line 2
        echo "    ";
        $context["itemsPerColumn"] = $this->getAttribute((isset($context["admin_pool"]) ? $context["admin_pool"] : null), "getOption", array(0 => "dropdown_number_groups_per_colums"), "method");
        // line 3
        echo "    ";
        $context["columnsCount"] = twig_round((twig_length_filter($this->env, $this->getAttribute((isset($context["admin_pool"]) ? $context["admin_pool"] : null), "dashboardgroups")) / (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)));
        // line 4
        echo "

    <ul class=\"dropdown-menu";
        // line 6
        if (((isset($context["columnsCount"]) ? $context["columnsCount"] : null) > 1)) {
            echo " multi-column";
        }
        echo " dropdown-add\"
        ";
        // line 7
        if (((isset($context["columnsCount"]) ? $context["columnsCount"] : null) > 1)) {
            echo "style=\"width: ";
            echo twig_escape_filter($this->env, ((isset($context["columnsCount"]) ? $context["columnsCount"] : null) * 140), "html", null, true);
            echo "px;\"";
        }
        // line 8
        echo "            >
        ";
        // line 9
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["admin_pool"]) ? $context["admin_pool"] : null), "dashboardgroups"));
        $context['loop'] = array(
          'parent' => $context['_parent'],
          'index0' => 0,
          'index'  => 1,
          'first'  => true,
        );
        if (is_array($context['_seq']) || (is_object($context['_seq']) && $context['_seq'] instanceof Countable)) {
            $length = count($context['_seq']);
            $context['loop']['revindex0'] = $length - 1;
            $context['loop']['revindex'] = $length;
            $context['loop']['length'] = $length;
            $context['loop']['last'] = 1 === $length;
        }
        foreach ($context['_seq'] as $context["_key"] => $context["group"]) {
            // line 10
            echo "            ";
            $context["display"] = (twig_test_empty($this->getAttribute((isset($context["group"]) ? $context["group"] : null), "roles")) || $this->env->getExtension('security')->isGranted("ROLE_SUPER_ADMIN"));
            // line 11
            echo "            ";
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["group"]) ? $context["group"] : null), "roles"));
            foreach ($context['_seq'] as $context["_key"] => $context["role"]) {
                if ((!(isset($context["display"]) ? $context["display"] : null))) {
                    // line 12
                    echo "                ";
                    $context["display"] = $this->env->getExtension('security')->isGranted((isset($context["role"]) ? $context["role"] : null));
                    // line 13
                    echo "            ";
                }
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['_key'], $context['role'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 14
            echo "
            ";
            // line 16
            echo "            ";
            $context["item_count"] = 0;
            // line 17
            echo "            ";
            if ((isset($context["display"]) ? $context["display"] : null)) {
                // line 18
                echo "                ";
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["group"]) ? $context["group"] : null), "items"));
                foreach ($context['_seq'] as $context["_key"] => $context["admin"]) {
                    if (((isset($context["item_count"]) ? $context["item_count"] : null) == 0)) {
                        // line 19
                        echo "                    ";
                        if (($this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "hasroute", array(0 => "list"), "method") && $this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "isGranted", array(0 => "LIST"), "method"))) {
                            // line 20
                            echo "                        ";
                            $context["item_count"] = ((isset($context["item_count"]) ? $context["item_count"] : null) + 1);
                            // line 21
                            echo "                    ";
                        }
                        // line 22
                        echo "                ";
                    }
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['_key'], $context['admin'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 23
                echo "            ";
            }
            // line 24
            echo "
            ";
            // line 25
            if (((isset($context["display"]) ? $context["display"] : null) && ((isset($context["item_count"]) ? $context["item_count"] : null) > 0))) {
                // line 26
                echo "                ";
                if ((((isset($context["columnsCount"]) ? $context["columnsCount"] : null) > 1) && (($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "index0") % (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)) == 0))) {
                    // line 27
                    echo "                    ";
                    if ($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "first")) {
                        // line 28
                        echo "                        <div class=\"row\">
                    ";
                    }
                    // line 30
                    echo "                    <div class=\"col-md-";
                    echo twig_escape_filter($this->env, twig_round((12 / (isset($context["columnsCount"]) ? $context["columnsCount"] : null))), "html", null, true);
                    echo "\">
                    <ul class=\"dropdown-menu\">
                ";
                }
                // line 33
                echo "
                <li role=\"presentation\" class=\"dropdown-header\">";
                // line 34
                echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["group"]) ? $context["group"] : null), "label"), array(), $this->getAttribute((isset($context["group"]) ? $context["group"] : null), "label_catalogue")), "html", null, true);
                echo "</li>
                ";
                // line 35
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["group"]) ? $context["group"] : null), "items"));
                foreach ($context['_seq'] as $context["_key"] => $context["admin"]) {
                    // line 36
                    echo "                    ";
                    if (($this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "hasroute", array(0 => "create"), "method") && $this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "isGranted", array(0 => "CREATE"), "method"))) {
                        // line 37
                        echo "                        <li role=\"presentation\">
                            <a role=\"menuitem\" tabindex=\"-1\" href=\"";
                        // line 38
                        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "generateUrl", array(0 => "create"), "method"), "html", null, true);
                        echo "\">";
                        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans($this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "label"), array(), $this->getAttribute((isset($context["admin"]) ? $context["admin"] : null), "translationdomain")), "html", null, true);
                        echo "</a>
                        </li>
                    ";
                    }
                    // line 41
                    echo "                ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['_key'], $context['admin'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 42
                echo "
                ";
                // line 43
                if (((!$this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "last")) && (($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "index") % (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)) != 0))) {
                    // line 44
                    echo "                    <li role=\"presentation\" class=\"divider\"></li>
                ";
                }
                // line 46
                echo "
            ";
                // line 47
                if ((($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "length") > (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)) && (($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "index") % (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)) == 0))) {
                    // line 48
                    echo "                </ul>
                </div>
            ";
                }
                // line 51
                echo "                ";
                if ((($this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "length") > (isset($context["itemsPerColumn"]) ? $context["itemsPerColumn"] : null)) && $this->getAttribute((isset($context["loop"]) ? $context["loop"] : null), "last"))) {
                    // line 52
                    echo "                    </div>
                ";
                }
                // line 54
                echo "            ";
            }
            // line 55
            echo "        ";
            ++$context['loop']['index0'];
            ++$context['loop']['index'];
            $context['loop']['first'] = false;
            if (isset($context['loop']['length'])) {
                --$context['loop']['revindex0'];
                --$context['loop']['revindex'];
                $context['loop']['last'] = 0 === $context['loop']['revindex0'];
            }
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['_key'], $context['group'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 56
        echo "    </ul>
";
    }

    public function getTemplateName()
    {
        return "SonataAdminBundle:Core:add_block.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  118 => 23,  778 => 251,  763 => 244,  760 => 243,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 233,  714 => 232,  711 => 231,  703 => 226,  700 => 225,  653 => 218,  650 => 217,  644 => 213,  633 => 209,  616 => 207,  599 => 206,  595 => 205,  587 => 203,  584 => 202,  581 => 201,  578 => 200,  573 => 198,  546 => 166,  534 => 162,  531 => 161,  521 => 182,  513 => 179,  499 => 173,  475 => 169,  473 => 168,  468 => 160,  454 => 156,  448 => 153,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 114,  330 => 112,  307 => 104,  300 => 102,  291 => 99,  286 => 98,  190 => 66,  321 => 109,  295 => 100,  274 => 135,  242 => 82,  236 => 109,  70 => 29,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 250,  947 => 249,  939 => 243,  936 => 242,  934 => 241,  931 => 240,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 229,  900 => 228,  897 => 227,  894 => 226,  892 => 225,  889 => 224,  881 => 220,  878 => 219,  876 => 218,  873 => 217,  865 => 213,  862 => 212,  860 => 211,  857 => 210,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 197,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 183,  793 => 182,  785 => 178,  783 => 177,  780 => 176,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 164,  751 => 163,  749 => 162,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 148,  699 => 142,  697 => 141,  696 => 140,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 113,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 193,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 180,  512 => 84,  509 => 83,  503 => 81,  496 => 172,  493 => 171,  478 => 74,  467 => 72,  456 => 68,  450 => 64,  428 => 59,  414 => 144,  408 => 142,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 21,  332 => 20,  316 => 16,  313 => 15,  290 => 5,  276 => 395,  266 => 366,  263 => 365,  255 => 353,  245 => 83,  207 => 269,  194 => 248,  76 => 27,  200 => 54,  184 => 233,  157 => 37,  83 => 37,  58 => 24,  170 => 79,  139 => 169,  563 => 188,  560 => 191,  558 => 190,  553 => 188,  549 => 182,  543 => 179,  537 => 176,  532 => 174,  528 => 160,  525 => 172,  523 => 171,  518 => 170,  514 => 168,  511 => 167,  508 => 165,  501 => 174,  491 => 157,  487 => 156,  460 => 143,  455 => 141,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 121,  411 => 143,  405 => 141,  403 => 48,  380 => 130,  366 => 125,  354 => 101,  331 => 96,  325 => 94,  308 => 13,  304 => 103,  272 => 91,  267 => 78,  249 => 74,  216 => 100,  155 => 52,  146 => 34,  126 => 26,  124 => 25,  188 => 48,  181 => 232,  161 => 57,  320 => 92,  317 => 107,  311 => 14,  288 => 4,  284 => 106,  279 => 104,  275 => 103,  256 => 86,  250 => 341,  237 => 79,  232 => 78,  222 => 297,  191 => 246,  153 => 72,  150 => 35,  145 => 52,  110 => 42,  692 => 399,  683 => 223,  678 => 133,  676 => 385,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 368,  635 => 117,  631 => 364,  625 => 361,  615 => 354,  607 => 349,  597 => 342,  590 => 204,  583 => 334,  579 => 332,  577 => 329,  575 => 328,  569 => 325,  565 => 324,  555 => 189,  548 => 313,  540 => 164,  536 => 306,  529 => 92,  524 => 90,  516 => 294,  510 => 178,  504 => 175,  500 => 291,  495 => 158,  490 => 77,  486 => 286,  482 => 285,  470 => 167,  464 => 71,  459 => 159,  452 => 268,  434 => 256,  421 => 244,  417 => 145,  400 => 47,  385 => 41,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 171,  302 => 168,  296 => 167,  282 => 161,  259 => 87,  244 => 140,  231 => 133,  226 => 131,  215 => 280,  186 => 47,  152 => 62,  114 => 111,  104 => 18,  96 => 18,  358 => 123,  351 => 120,  347 => 134,  343 => 115,  338 => 113,  327 => 111,  323 => 125,  319 => 124,  315 => 150,  301 => 144,  299 => 8,  293 => 6,  289 => 140,  281 => 96,  277 => 136,  271 => 374,  265 => 130,  262 => 88,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 97,  228 => 83,  225 => 298,  213 => 69,  211 => 81,  197 => 90,  174 => 42,  148 => 64,  134 => 55,  127 => 48,  270 => 157,  253 => 342,  233 => 304,  212 => 76,  210 => 270,  206 => 74,  202 => 266,  198 => 66,  192 => 88,  185 => 63,  180 => 66,  175 => 74,  172 => 51,  167 => 57,  165 => 77,  160 => 38,  137 => 46,  120 => 51,  113 => 43,  100 => 40,  90 => 16,  81 => 33,  65 => 27,  129 => 27,  97 => 39,  84 => 32,  34 => 18,  53 => 23,  37 => 17,  52 => 19,  77 => 12,  74 => 30,  20 => 1,  23 => 18,  480 => 75,  474 => 150,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 140,  398 => 115,  393 => 137,  387 => 110,  384 => 109,  381 => 120,  379 => 119,  374 => 128,  368 => 126,  365 => 141,  362 => 110,  360 => 104,  355 => 122,  341 => 131,  337 => 22,  322 => 93,  314 => 88,  312 => 149,  309 => 148,  305 => 115,  298 => 101,  294 => 90,  285 => 3,  283 => 97,  278 => 95,  268 => 373,  264 => 2,  258 => 354,  252 => 85,  247 => 84,  241 => 77,  229 => 73,  220 => 290,  214 => 99,  177 => 43,  169 => 62,  140 => 52,  132 => 28,  128 => 47,  111 => 22,  107 => 41,  61 => 27,  273 => 394,  269 => 133,  254 => 147,  246 => 99,  243 => 327,  240 => 326,  238 => 312,  235 => 311,  230 => 106,  227 => 301,  224 => 103,  221 => 79,  219 => 101,  217 => 56,  208 => 124,  204 => 267,  179 => 44,  159 => 196,  143 => 33,  135 => 51,  131 => 160,  119 => 45,  108 => 21,  102 => 19,  71 => 11,  67 => 31,  63 => 24,  59 => 28,  47 => 22,  38 => 18,  94 => 16,  89 => 33,  85 => 31,  79 => 28,  75 => 33,  68 => 10,  56 => 21,  50 => 23,  29 => 3,  87 => 14,  72 => 37,  55 => 25,  21 => 11,  26 => 2,  98 => 47,  93 => 17,  88 => 37,  78 => 34,  46 => 19,  27 => 14,  40 => 13,  44 => 21,  35 => 17,  31 => 15,  43 => 18,  41 => 19,  28 => 14,  201 => 72,  196 => 52,  183 => 46,  171 => 216,  166 => 209,  163 => 45,  158 => 55,  156 => 64,  151 => 52,  142 => 61,  138 => 49,  136 => 30,  123 => 52,  121 => 24,  117 => 51,  115 => 50,  105 => 20,  101 => 42,  91 => 56,  69 => 32,  66 => 27,  62 => 24,  49 => 21,  24 => 13,  32 => 4,  25 => 12,  22 => 12,  19 => 11,  209 => 75,  203 => 55,  199 => 265,  193 => 51,  189 => 240,  187 => 64,  182 => 85,  176 => 82,  173 => 65,  168 => 41,  164 => 59,  162 => 68,  154 => 36,  149 => 182,  147 => 52,  144 => 51,  141 => 58,  133 => 50,  130 => 49,  125 => 46,  122 => 45,  116 => 44,  112 => 52,  109 => 46,  106 => 104,  103 => 43,  99 => 41,  95 => 41,  92 => 38,  86 => 36,  82 => 33,  80 => 13,  73 => 29,  64 => 3,  60 => 22,  57 => 20,  54 => 23,  51 => 9,  48 => 8,  45 => 20,  42 => 7,  39 => 15,  36 => 6,  33 => 16,  30 => 15,);
    }
}
