<?php
$_SESSION['REDIRECT'] = 'pieces';

if (!isset($_SESSION['user'])) {
    header( 'Location: http://icsproject.jasonfavrod.com/login' );
}
?>
<div class="col-md-8 col-md-offset-1">
  <h3 class="table-title">Pieces</h3>
  <table id="pieces-table" class="table table-bordered table-hover">
    <tr>
      <th id="pieces-title-th">Title</th>
      <th id="pieces-artist-th">Artist</th>
      <th id="pieces-style-th">Style</th>
      <th id="pieces-subcategory-th">Subcategory</th>
    </tr>
    
    <tr>
      <td><input id="piece-title" class="input-wide" type="text"></td>
      <td><select id="piece-artist"></select></td>
      <td><select id="piece-style"></select></td>
      <td><select id="piece-subcategory"></select> <button id="enter-piece" class="btn btn-primary">✓</button></td>
    </tr>
  </table>

</div>


<div class="col-md-2">
  <div class="panel panel-default">

    <div id="style-heading" class="panel-heading">
      <h3 class="panel-title">Categories <span id="style-heading-span">(click to add new style)</span></h3>
    </div>

    <div id="styles" class="panel-body">
      <button id="add-subcat">Add Subcategory</button>
      <input id="add-subcat-in" type="text">
      <ul id="subcat-list" class="list-group"></ul>
    </div>

  </div>
</div>


<script src="/js/pieces.js"></script>
