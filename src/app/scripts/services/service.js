(function () {
    'use strict';

    angular.module('fs-angular-icon',[])
    .provider('fsIcon', function() {

        var _options = { dataUrl: 'https://spreadsheets.google.com/feeds/list/1tftyNypXdc6bX3EIXH3kG49AV14irkHaxgm6K81jssQ/od6/public/basic?alt=json' };

        this.options = function(value) {
            _options = angular.extend(_options,value);
        }

        this.$get = function($timeout, $mdDialog, $q, $http) {

            var service = {
                show: show
            };

            var _icons = [];
            $http.get(_options.dataUrl)
            .then(function(response) {
                angular.forEach(response.data.feed.entry,function(item) {

                    var icon = { value: item.title.$t, keywords: '' };
                    angular.forEach(item.content.$t.split(','),function(item) {

                        item = item.match(/([^:]+):([^:]+)/);
                        if(item) {
                            icon[item[1].trim()] = item[2].trim();
                        }
                    });

                    if(!icon.disable) {
                        _icons.push(icon);
                    }
                });
            });

            return service;

            function show() {

                return $q(function(resolve) {

                    $mdDialog
                    .show({ templateUrl: 'views/directives/icon.html',
                            title: 'Attention',
                            clickOutsideToClose: true,
                            ok: 'Ok',
                            controllerAs: 'dialog',
                            preserveScope: true,
                            skipHide: true,
                            controller: 'fsIconCtrl',
                            resolve: {
                                icons: function() {
                                    return _icons;
                                }
                            }
                    })
                    .then(function(icon) {
                        resolve(icon);
                    })
                    .finally(function() {
                        angular.element(document.querySelectorAll('md-tooltip')).remove();
                    });
                });
            }
        };
    })
    .controller('fsIconCtrl',function($scope, $mdDialog, $timeout, icons) {

        $scope.search = '';
        $scope.icons = icons;
        $scope.hideIcons = {};
        $scope.tooltip = false;

        $scope.$watch('search',function(search) {
            $scope.hideIcons = {};
            if(search.toLowerCase().length) {
                for (var i = 0, len = $scope.icons.length; i < len; i++) {
                    if($scope.icons[i].value.indexOf(search.toLowerCase())<0 && $scope.icons[i].keywords.indexOf(search.toLowerCase())<0) {
                        $scope.hideIcons[$scope.icons[i].value] = true;
                    }
                }
            }
        });

        $scope.hide = function() {
            $mdDialog.hide();
        }

        $scope.select = function(icon) {
            $mdDialog.hide(icon);
        }
    })
})();