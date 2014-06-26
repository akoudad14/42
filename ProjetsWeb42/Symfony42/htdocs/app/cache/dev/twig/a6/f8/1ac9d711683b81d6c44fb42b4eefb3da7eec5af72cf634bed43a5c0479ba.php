<?php

/* WebProfilerBundle:Collector:form.html.twig */
class __TwigTemplate_a6f81ac9d711683b81d6c44fb42b4eefb3da7eec5af72cf634bed43a5c0479ba extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("@WebProfiler/Profiler/layout.html.twig");

        $this->blocks = array(
            'toolbar' => array($this, 'block_toolbar'),
            'menu' => array($this, 'block_menu'),
            'panel' => array($this, 'block_panel'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "@WebProfiler/Profiler/layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 3
        $context["__internal_d13274010eceb3aec45aae4bc31ba234e2878cff8e8dd83a47faff2da815e78a"] = $this;
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 5
    public function block_toolbar($context, array $blocks = array())
    {
        // line 6
        echo "    ";
        if (twig_length_filter($this->env, $this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"))) {
            // line 7
            echo "        ";
            ob_start();
            // line 8
            echo "            <img width=\"20\" height=\"28\" alt=\"Forms\" src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAcCAYAAABh2p9gAAAAYElEQVRIiWNgGHGAEZ+knZ3df2zihw4dwqmPiVIXoQMMm3C5ChdAdy0LsgH4vIIPIJtBdS9T3UAWdAFyvQ0DjKRGAiEwQsIQOdioHoYoLqRGwh514VB0IakWjsC8PAIBAMl9LomdN/ohAAAAAElFTkSuQmCC\"/>
            <span class=\"sf-toolbar-status sf-toolbar-status-";
            // line 9
            if ($this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "nb_errors")) {
                echo "red";
            } else {
                echo "green";
            }
            echo "\">";
            if ($this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "nb_errors")) {
                echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "nb_errors"), "html", null, true);
            } else {
                echo twig_escape_filter($this->env, twig_length_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms")), "html", null, true);
            }
            echo "</span>
        ";
            $context["icon"] = ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
            // line 11
            echo "
        ";
            // line 12
            $this->env->loadTemplate("@WebProfiler/Profiler/toolbar_item.html.twig")->display(array_merge($context, array("link" => (isset($context["profiler_url"]) ? $context["profiler_url"] : $this->getContext($context, "profiler_url")))));
            // line 13
            echo "    ";
        }
    }

    // line 16
    public function block_menu($context, array $blocks = array())
    {
        // line 17
        echo "    <span class=\"label\">
        <span class=\"icon\"><img src=\"data:image/png;base64,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\" alt=\"\"/></span>
        <strong>Forms</strong>
        ";
        // line 20
        if (twig_length_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms"))) {
            // line 21
            echo "            <span class=\"count\"><span>";
            echo twig_escape_filter($this->env, twig_length_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms")), "html", null, true);
            echo "</span></span>
        ";
        }
        // line 23
        echo "    </span>
";
    }

    // line 26
    public function block_panel($context, array $blocks = array())
    {
        // line 27
        echo "    <style type=\"text/css\">
    .window {
        /*background: #F6F6F6;*/
        margin: -30px -40px -40px;
    }
    .tree {
        width: 230px;
        padding: 10px;
        font-size: 12px;
        float: left;
    }
    #content .tree h2 {
        font-size: 13px;
        padding: 5px 7px;
        margin: 0;
    }
    .tree li {
        margin: 0;
        padding: 0;
        width: 100%;
    }
    .tree a {
        text-decoration: none;
        display: block;
        padding: 5px 7px;
        border-radius: 6px;
        color: #313131;
    }
    .tree ul ul a {
        padding-left: 22px;
    }
    .tree ul ul ul a {
        padding-left: 37px;
    }
    .tree ul ul ul ul a {
        padding-left: 52px;
    }
    .tree ul ul ul ul ul a {
        padding-left: 67px;
    }
    .tree a:hover {
        background: #dfdfdf;
    }
    .tree a.active, a.active:hover {
        background: #dfdfdf;
        font-weight: bold;
        color: #313131;
    }
    .tree-details {
        border-left: 1px solid #dfdfdf;
        background: white;
        margin-left: 250px;
        padding: 30px 40px 40px;
    }
    .form-type {
        color: #999999;
    }
    .hidden {
        display: none;
    }
    </style>

    ";
        // line 89
        if (twig_length_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms"))) {
            // line 90
            echo "        <div class=\"window\">
            <div class=\"tree\">
                <h2>Forms</h2>

                <ul>
                ";
            // line 95
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable($this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms"));
            foreach ($context['_seq'] as $context["formName"] => $context["formData"]) {
                // line 96
                echo "                    ";
                echo $context["__internal_d13274010eceb3aec45aae4bc31ba234e2878cff8e8dd83a47faff2da815e78a"]->getform_tree_entry((isset($context["formName"]) ? $context["formName"] : $this->getContext($context, "formName")), (isset($context["formData"]) ? $context["formData"] : $this->getContext($context, "formData")));
                echo "
                ";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['formName'], $context['formData'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 98
            echo "                </ul>
            </div>

            ";
            // line 101
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable($this->getAttribute($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "data"), "forms"));
            foreach ($context['_seq'] as $context["formName"] => $context["formData"]) {
                // line 102
                echo "                ";
                echo $context["__internal_d13274010eceb3aec45aae4bc31ba234e2878cff8e8dd83a47faff2da815e78a"]->getform_tree_details((isset($context["formName"]) ? $context["formName"] : $this->getContext($context, "formName")), (isset($context["formData"]) ? $context["formData"] : $this->getContext($context, "formData")));
                echo "
            ";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['formName'], $context['formData'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 104
            echo "        </div>
    ";
        } else {
            // line 106
            echo "        <p><em>No forms were submitted for this request.</em></p>
    ";
        }
        // line 108
        echo "
    <script>
    function TabView() {
        var _activeLink = null,
            _activeView = null;

        this.init = function () {
            var links = document.querySelectorAll('.tree a'),
                views = document.querySelectorAll('.tree-details'),
                i,
                l;

            for (i = 0, l = links.length; i < l; ++i) {
                (function () {
                    var link = links[i];

                    link.addEventListener('click', function (e) {
                        var href = link.getAttribute('href'),
                            targetId = href.substr(href.indexOf('#') + 1),
                            view = document.getElementById(targetId);

                        if (view) {
                            if (null !== _activeLink) {
                                Sfjs.removeClass(_activeLink, 'active');
                            }

                            if (null !== _activeView) {
                                Sfjs.addClass(_activeView, 'hidden');
                            }

                            Sfjs.addClass(link, 'active');
                            Sfjs.removeClass(view, 'hidden');

                            _activeLink = link;
                            _activeView = view;
                        }

                        e.preventDefault();

                        return false;
                    })
                }());
            }

            for (i = 0, l = views.length; i < l; ++i) {
                Sfjs.addClass(views[i], 'hidden');
            }

            if (links.length > 0) {
                Sfjs.addClass(links[0], 'active');
                _activeLink = links[0];

                if (views.length > 0) {
                    Sfjs.removeClass(views[0], 'hidden');
                    _activeView = views[0];
                }
            }
        }
    }

    var tabView = new TabView();

    tabView.init();
    </script>
";
    }

    // line 174
    public function getform_tree_entry($_name = null, $_data = null)
    {
        $context = $this->env->mergeGlobals(array(
            "name" => $_name,
            "data" => $_data,
        ));

        $blocks = array();

        ob_start();
        try {
            // line 175
            echo "    <li>
        <a href=\"#details_";
            // line 176
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "id"), "html", null, true);
            echo "\">";
            echo twig_escape_filter($this->env, (isset($context["name"]) ? $context["name"] : $this->getContext($context, "name")), "html", null, true);
            echo "</a>

        ";
            // line 178
            if ((!twig_test_empty($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "children")))) {
                // line 179
                echo "            <ul>
                ";
                // line 180
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "children"));
                foreach ($context['_seq'] as $context["childName"] => $context["childData"]) {
                    // line 181
                    echo "                    ";
                    echo $this->getAttribute($this, "form_tree_entry", array(0 => (isset($context["childName"]) ? $context["childName"] : $this->getContext($context, "childName")), 1 => (isset($context["childData"]) ? $context["childData"] : $this->getContext($context, "childData"))), "method");
                    echo "
                ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['childName'], $context['childData'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 183
                echo "            </ul>
        ";
            }
            // line 185
            echo "    </li>
";
        } catch (Exception $e) {
            ob_end_clean();

            throw $e;
        }

        return ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
    }

    // line 188
    public function getform_tree_details($_name = null, $_data = null)
    {
        $context = $this->env->mergeGlobals(array(
            "name" => $_name,
            "data" => $_data,
        ));

        $blocks = array();

        ob_start();
        try {
            // line 189
            echo "    <div class=\"tree-details\" id=\"details_";
            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "id"), "html", null, true);
            echo "\">
        <h2>
            ";
            // line 191
            echo twig_escape_filter($this->env, (isset($context["name"]) ? $context["name"] : $this->getContext($context, "name")), "html", null, true);
            echo "
            ";
            // line 192
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "type_class", array(), "any", true, true)) {
                // line 193
                echo "            <span class=\"form-type\">[<abbr title=\"";
                echo twig_escape_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "type_class"), "html", null, true);
                echo "\">";
                echo twig_escape_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "type"), "html", null, true);
                echo "</abbr>]</span>
            ";
            }
            // line 195
            echo "        </h2>

        ";
            // line 197
            if (($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "errors", array(), "any", true, true) && (twig_length_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "errors")) > 0))) {
                // line 198
                echo "        <h3>Errors</h3>

        <table>
            <tr>
                <th width=\"50%\">Message</th>
                <th>Cause</th>
            </tr>
            ";
                // line 205
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "errors"));
                foreach ($context['_seq'] as $context["_key"] => $context["error"]) {
                    // line 206
                    echo "            <tr>
                <td>";
                    // line 207
                    echo twig_escape_filter($this->env, $this->getAttribute((isset($context["error"]) ? $context["error"] : $this->getContext($context, "error")), "message"), "html", null, true);
                    echo "</td>
                <td><em>Unknown.</em></td>
            </tr>
            ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['_key'], $context['error'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 211
                echo "        </table>
        ";
            }
            // line 213
            echo "
        ";
            // line 214
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "default_data", array(), "any", true, true)) {
                // line 215
                echo "        <h3>Default Data</h3>

        <table>
            <tr>
                <th width=\"180\">Model Format</th>
                <td>
                    ";
                // line 221
                if ($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "default_data", array(), "any", false, true), "model", array(), "any", true, true)) {
                    // line 222
                    echo "                        <pre>";
                    echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "default_data"), "model"), "html", null, true);
                    echo "</pre>
                    ";
                } else {
                    // line 224
                    echo "                        <em>same as normalized format</em>
                    ";
                }
                // line 226
                echo "                </td>
            </tr>
            <tr>
                <th>Normalized Format</th>
                <td><pre>";
                // line 230
                echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "default_data"), "norm"), "html", null, true);
                echo "</pre></td>
            </tr>
            <tr>
                <th>View Format</th>
                <td>
                    ";
                // line 235
                if ($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "default_data", array(), "any", false, true), "view", array(), "any", true, true)) {
                    // line 236
                    echo "                        <pre>";
                    echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "default_data"), "view"), "html", null, true);
                    echo "</pre>
                    ";
                } else {
                    // line 238
                    echo "                        <em>same as normalized format</em>
                    ";
                }
                // line 240
                echo "                </td>
            </tr>
        </table>
        ";
            }
            // line 244
            echo "
        ";
            // line 245
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "submitted_data", array(), "any", true, true)) {
                // line 246
                echo "        <h3>Submitted Data</h3>

        ";
                // line 248
                if ($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "submitted_data", array(), "any", false, true), "norm", array(), "any", true, true)) {
                    // line 249
                    echo "            <table>
                <tr>
                    <th width=\"180\">View Format</th>
                    <td>
                        ";
                    // line 253
                    if ($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "submitted_data", array(), "any", false, true), "view", array(), "any", true, true)) {
                        // line 254
                        echo "                            <pre>";
                        echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "submitted_data"), "view"), "html", null, true);
                        echo "</pre>
                        ";
                    } else {
                        // line 256
                        echo "                            <em>same as normalized format</em>
                        ";
                    }
                    // line 258
                    echo "                    </td>
                </tr>
                <tr>
                    <th>Normalized Format</th>
                    <td><pre>";
                    // line 262
                    echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "submitted_data"), "norm"), "html", null, true);
                    echo "</pre></td>
                </tr>
                <tr>
                    <th>Model Format</th>
                    <td>
                        ";
                    // line 267
                    if ($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "submitted_data", array(), "any", false, true), "model", array(), "any", true, true)) {
                        // line 268
                        echo "                            <pre>";
                        echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "submitted_data"), "model"), "html", null, true);
                        echo "</pre>
                        ";
                    } else {
                        // line 270
                        echo "                            <em>same as normalized format</em>
                        ";
                    }
                    // line 272
                    echo "                    </td>
                </tr>
            </table>
        ";
                } else {
                    // line 276
                    echo "            <p><em>This form was not submitted.</em></p>
        ";
                }
                // line 278
                echo "        ";
            }
            // line 279
            echo "
        ";
            // line 280
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "passed_options", array(), "any", true, true)) {
                // line 281
                echo "        <h3>Passed Options</h3>

        ";
                // line 283
                if (twig_length_filter($this->env, $this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "passed_options"))) {
                    // line 284
                    echo "        <table>
            <tr>
                <th width=\"180\">Option</th>
                <th>Passed Value</th>
                <th>Resolved Value</th>
            </tr>
            ";
                    // line 290
                    $context['_parent'] = (array) $context;
                    $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "passed_options"));
                    foreach ($context['_seq'] as $context["option"] => $context["value"]) {
                        // line 291
                        echo "            <tr>
                <th>";
                        // line 292
                        echo twig_escape_filter($this->env, (isset($context["option"]) ? $context["option"] : $this->getContext($context, "option")), "html", null, true);
                        echo "</th>
                <td><pre>";
                        // line 293
                        echo twig_escape_filter($this->env, (isset($context["value"]) ? $context["value"] : $this->getContext($context, "value")), "html", null, true);
                        echo "</pre></td>
                <td>
                    ";
                        // line 295
                        if (($this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "resolved_options"), (isset($context["option"]) ? $context["option"] : $this->getContext($context, "option")), array(), "array") === (isset($context["value"]) ? $context["value"] : $this->getContext($context, "value")))) {
                            // line 296
                            echo "                        <em>same as passed value</em>
                    ";
                        } else {
                            // line 298
                            echo "                        <pre>";
                            echo twig_escape_filter($this->env, $this->getAttribute($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "resolved_options"), (isset($context["option"]) ? $context["option"] : $this->getContext($context, "option")), array(), "array"), "html", null, true);
                            echo "</pre>
                    ";
                        }
                        // line 300
                        echo "                </td>
            </tr>
            ";
                    }
                    $_parent = $context['_parent'];
                    unset($context['_seq'], $context['_iterated'], $context['option'], $context['value'], $context['_parent'], $context['loop']);
                    $context = array_intersect_key($context, $_parent) + $_parent;
                    // line 303
                    echo "        </table>
        ";
                } else {
                    // line 305
                    echo "        <p><em>No options where passed when constructing this form.</em></p>
        ";
                }
                // line 307
                echo "        ";
            }
            // line 308
            echo "
        ";
            // line 309
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "resolved_options", array(), "any", true, true)) {
                // line 310
                echo "        <h3>Resolved Options</h3>

        <table>
            <tr>
                <th width=\"180\">Option</th>
                <th>Value</th>
            </tr>
            ";
                // line 317
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "resolved_options"));
                foreach ($context['_seq'] as $context["option"] => $context["value"]) {
                    // line 318
                    echo "            <tr>
                <th>";
                    // line 319
                    echo twig_escape_filter($this->env, (isset($context["option"]) ? $context["option"] : $this->getContext($context, "option")), "html", null, true);
                    echo "</th>
                <td><pre>";
                    // line 320
                    echo twig_escape_filter($this->env, (isset($context["value"]) ? $context["value"] : $this->getContext($context, "value")), "html", null, true);
                    echo "</pre></td>
            </tr>
            ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['option'], $context['value'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 323
                echo "        </table>
        ";
            }
            // line 325
            echo "
        ";
            // line 326
            if ($this->getAttribute((isset($context["data"]) ? $context["data"] : null), "view_vars", array(), "any", true, true)) {
                // line 327
                echo "        <h3>View Variables</h3>

        <table>
            <tr>
                <th width=\"180\">Variable</th>
                <th>Value</th>
            </tr>
            ";
                // line 334
                $context['_parent'] = (array) $context;
                $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "view_vars"));
                foreach ($context['_seq'] as $context["variable"] => $context["value"]) {
                    // line 335
                    echo "            <tr>
                <th>";
                    // line 336
                    echo twig_escape_filter($this->env, (isset($context["variable"]) ? $context["variable"] : $this->getContext($context, "variable")), "html", null, true);
                    echo "</th>
                <td><pre>";
                    // line 337
                    echo twig_escape_filter($this->env, (isset($context["value"]) ? $context["value"] : $this->getContext($context, "value")), "html", null, true);
                    echo "</pre></td>
            </tr>
            ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['variable'], $context['value'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 340
                echo "        </table>
        ";
            }
            // line 342
            echo "    </div>

    ";
            // line 344
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["data"]) ? $context["data"] : $this->getContext($context, "data")), "children"));
            foreach ($context['_seq'] as $context["childName"] => $context["childData"]) {
                // line 345
                echo "        ";
                echo $this->getAttribute($this, "form_tree_details", array(0 => (isset($context["childName"]) ? $context["childName"] : $this->getContext($context, "childName")), 1 => (isset($context["childData"]) ? $context["childData"] : $this->getContext($context, "childData"))), "method");
                echo "
    ";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['childName'], $context['childData'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
        } catch (Exception $e) {
            ob_end_clean();

            throw $e;
        }

        return ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
    }

    public function getTemplateName()
    {
        return "WebProfilerBundle:Collector:form.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  672 => 345,  664 => 342,  651 => 337,  622 => 323,  613 => 320,  609 => 319,  606 => 318,  602 => 317,  591 => 309,  552 => 293,  541 => 290,  533 => 284,  519 => 278,  505 => 270,  489 => 262,  483 => 258,  465 => 249,  438 => 236,  397 => 213,  383 => 207,  367 => 198,  353 => 193,  462 => 202,  446 => 197,  441 => 196,  431 => 189,  394 => 168,  205 => 108,  234 => 94,  297 => 179,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 344,  665 => 196,  663 => 195,  660 => 340,  657 => 193,  647 => 336,  632 => 187,  629 => 326,  626 => 325,  610 => 181,  603 => 179,  600 => 178,  588 => 308,  570 => 164,  561 => 161,  554 => 224,  522 => 279,  479 => 256,  471 => 253,  451 => 120,  418 => 224,  373 => 156,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 307,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 296,  551 => 221,  545 => 291,  526 => 190,  507 => 156,  497 => 267,  485 => 124,  463 => 248,  447 => 113,  424 => 114,  412 => 222,  410 => 221,  406 => 111,  404 => 90,  401 => 172,  391 => 163,  376 => 205,  369 => 148,  359 => 144,  333 => 132,  329 => 188,  326 => 86,  318 => 86,  261 => 104,  195 => 112,  306 => 95,  303 => 122,  292 => 119,  287 => 77,  280 => 87,  178 => 66,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 335,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 305,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 283,  521 => 182,  513 => 230,  499 => 268,  475 => 169,  473 => 254,  468 => 128,  454 => 244,  448 => 240,  445 => 152,  429 => 188,  422 => 226,  399 => 139,  396 => 138,  348 => 140,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 180,  291 => 115,  286 => 112,  190 => 72,  321 => 128,  295 => 178,  274 => 111,  242 => 82,  236 => 92,  70 => 19,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 334,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 310,  576 => 199,  564 => 162,  557 => 295,  550 => 187,  547 => 93,  527 => 281,  515 => 276,  512 => 84,  509 => 272,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 230,  414 => 144,  408 => 176,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 137,  335 => 134,  332 => 88,  316 => 132,  313 => 183,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 75,  194 => 70,  76 => 25,  200 => 72,  184 => 101,  58 => 20,  170 => 96,  563 => 298,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 280,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 198,  442 => 151,  439 => 195,  436 => 235,  433 => 149,  426 => 58,  420 => 146,  415 => 180,  411 => 143,  405 => 108,  403 => 48,  380 => 206,  366 => 150,  354 => 101,  331 => 135,  325 => 129,  308 => 126,  304 => 181,  272 => 108,  267 => 101,  249 => 74,  216 => 79,  155 => 87,  146 => 81,  126 => 47,  124 => 68,  188 => 102,  181 => 65,  161 => 63,  320 => 127,  317 => 185,  311 => 128,  288 => 176,  284 => 114,  279 => 77,  275 => 105,  256 => 96,  250 => 99,  237 => 92,  232 => 91,  222 => 85,  191 => 67,  153 => 56,  150 => 55,  110 => 60,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 327,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 303,  575 => 328,  569 => 300,  565 => 324,  555 => 200,  548 => 292,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 246,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 214,  385 => 159,  361 => 195,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 84,  215 => 37,  186 => 69,  152 => 86,  114 => 62,  104 => 35,  358 => 123,  351 => 192,  347 => 191,  343 => 92,  338 => 135,  327 => 131,  323 => 128,  319 => 124,  315 => 125,  301 => 80,  299 => 8,  293 => 90,  289 => 113,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 98,  260 => 363,  257 => 103,  251 => 101,  248 => 94,  239 => 93,  228 => 88,  225 => 86,  213 => 78,  211 => 83,  197 => 104,  174 => 98,  148 => 83,  134 => 54,  127 => 62,  270 => 102,  253 => 78,  233 => 87,  212 => 34,  210 => 33,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 66,  180 => 103,  175 => 65,  172 => 64,  167 => 95,  165 => 60,  160 => 91,  137 => 77,  113 => 48,  100 => 39,  90 => 26,  81 => 23,  65 => 22,  129 => 71,  97 => 27,  84 => 24,  34 => 14,  53 => 12,  77 => 20,  20 => 11,  23 => 5,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 245,  453 => 199,  444 => 238,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 215,  398 => 88,  393 => 211,  387 => 164,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 197,  362 => 148,  360 => 128,  355 => 143,  341 => 189,  337 => 90,  322 => 93,  314 => 88,  312 => 124,  309 => 82,  305 => 124,  298 => 120,  294 => 90,  285 => 175,  283 => 97,  278 => 106,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 90,  229 => 85,  220 => 81,  214 => 63,  177 => 102,  169 => 95,  140 => 58,  132 => 66,  128 => 83,  107 => 59,  61 => 17,  273 => 174,  269 => 109,  254 => 102,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 89,  227 => 92,  224 => 39,  221 => 41,  219 => 87,  217 => 38,  208 => 124,  204 => 82,  179 => 98,  159 => 90,  143 => 87,  135 => 76,  119 => 40,  102 => 40,  71 => 31,  67 => 20,  63 => 18,  59 => 11,  38 => 7,  94 => 44,  89 => 48,  85 => 23,  75 => 29,  68 => 33,  56 => 19,  87 => 34,  21 => 3,  26 => 4,  93 => 27,  88 => 32,  78 => 31,  46 => 13,  27 => 3,  44 => 9,  31 => 9,  28 => 10,  201 => 106,  196 => 52,  183 => 17,  171 => 81,  166 => 95,  163 => 92,  158 => 62,  156 => 58,  151 => 59,  142 => 30,  138 => 61,  136 => 72,  121 => 50,  117 => 57,  105 => 34,  91 => 33,  62 => 12,  49 => 14,  24 => 4,  25 => 6,  19 => 1,  79 => 21,  72 => 17,  69 => 16,  47 => 19,  40 => 11,  37 => 14,  22 => 2,  246 => 93,  157 => 89,  145 => 78,  139 => 77,  131 => 72,  123 => 42,  120 => 67,  115 => 56,  111 => 47,  108 => 53,  101 => 52,  98 => 51,  96 => 37,  83 => 33,  74 => 35,  66 => 26,  55 => 13,  52 => 12,  50 => 22,  43 => 12,  41 => 8,  35 => 6,  32 => 5,  29 => 7,  209 => 82,  203 => 73,  199 => 85,  193 => 51,  189 => 107,  187 => 77,  182 => 104,  176 => 63,  173 => 88,  168 => 61,  164 => 61,  162 => 59,  154 => 60,  149 => 91,  147 => 54,  144 => 80,  141 => 51,  133 => 67,  130 => 46,  125 => 51,  122 => 68,  116 => 39,  112 => 61,  109 => 52,  106 => 37,  103 => 55,  99 => 31,  95 => 51,  92 => 43,  86 => 38,  82 => 28,  80 => 27,  73 => 24,  64 => 13,  60 => 21,  57 => 21,  54 => 17,  51 => 16,  48 => 21,  45 => 9,  42 => 10,  39 => 6,  36 => 5,  33 => 4,  30 => 3,);
    }
}
