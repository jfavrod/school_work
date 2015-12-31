<?php
$_SESSION['REDIRECT'] = 'artists';

if (!isset($_SESSION['user'])) {
    header( 'Location: http://icsproject.jasonfavrod.com/login' );
}
?>

<div class="col-md-8 col-md-offset-1">
  <h3 class="table-title">Artist</h3>
  <table id="artist-table" class="table table-bordered table-hover">
    <tr>
      <th id="artist-name-th">Name</th>
      <th id="artist-dob-th">Birthday</th>
      <th id="artist-dod-th">Deceased</th>
      <th id="artist-age-th">Age</th>
      <th id="artist-country-th">Origin</th>
      <th id="artist-style-th">Style</th>
    </tr>

    <tr>
      <td><input id="artist-name" class="input-wide" type="text"></td>
      <td><input type="text" class="datepicker" id="artist-dob"></td>
      <td><input type="text" class="datepicker" id="artist-dod"></td>
      <td></td>
      <td><select id="artist-country"></select></td>
      <td><select id="artist-style"></select> <button id="enter-artist" class="btn btn-primary">✓</button></td>
    </tr>

  </table>

</div>

<div class="col-md-2">
  <div class="panel panel-default">

    <div id="style-heading" class="panel-heading">
      <h3 class="panel-title">Style</h3>
    </div>

    <div id="styles" class="panel-body">
      <button id="add-style-button">Add Style</button>
      <input id="add-style-in" type="text">
      <ul id="style-list" class="list-group"></ul>
    </div>

  </div>
</div>

<script src="/js/artists.js"></script>
