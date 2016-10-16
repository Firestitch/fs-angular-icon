<div class="fr">Server Time: <?=CMODEL_FORMAT::create(time())->iso8601(["seconds"=>true])?> seconds</div> 

<h1>Crons</h1>

<? APPLICATION::include_base_template("manage","crons",$this->get_vars()) ?>