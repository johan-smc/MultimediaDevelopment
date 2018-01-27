var gulp = require('gulp');
// create new instance of BrowserSync
var browserSync = require('browser-sync').create();

gulp.task('watch', function(gulpCallback) {
  browserSync.init({
    // serve out of app/
    server: './',
    // launch default browser as soon as server is up
    open: true
  }, function callback() {
    // (server is now up)

    // set up watch to reload browsers when source changes
    gulp.watch(['./index.html', './css/*', './js/*'], browserSync.reload);

    // notify gulp that this task is done
    gulpCallback();
  });
});

gulp.task('default', ['watch']);
