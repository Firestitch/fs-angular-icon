'use strict';


angular.module('app')
  .controller('DemoCtrl', function ($scope, fsIcon) {

  	$scope.icon = 'Not Selected';

    $scope.text = '';

    $scope.submit = function() {
        alert('submit');
    }

    $scope.open = function() {
	    fsIcon.show({ color: 'red' })
	  	.then(function(icon) {
	  		$scope.icon = icon;
	  	});
    }
});
