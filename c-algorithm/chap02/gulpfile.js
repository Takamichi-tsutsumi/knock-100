var   gulp = require('gulp'),
        watchify = require('watchify'),
        watch = require('gulp-watch'),
        shell = require('gulp-shell'),
        debug = require('gulp-debug');

gulp.task('compile-c', function() {
    return gulp.src('source/*.c')
        .pipe(shell([
            'gcc <%= file.path %> -o exec/a.out'
            ]));
});

gulp.task('watch', ['compile-c'], function() {
    gulp.watch('source/*.c', ['compile-c']);
});