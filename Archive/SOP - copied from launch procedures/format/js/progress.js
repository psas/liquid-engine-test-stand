$(document).ready(function() {


    // append checkboxes to all li tags
    $('<input type="checkbox" class="check">').prependTo('li').click(function () {
        var percent = (($(":checkbox:checked").length / $(":checkbox").length) * 100).toFixed(0) + "%";
        $('#complete .progress-bar').width(percent).html(percent);
    });
});
